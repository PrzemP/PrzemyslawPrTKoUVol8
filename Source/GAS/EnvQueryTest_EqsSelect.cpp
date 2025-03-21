// Copyright The Knights of Unity. All Rights Reserved.

#include "EnvQueryTest_EqsSelect.h"

#include "A_EQS_SELECT.h"
#include "EnvironmentQuery/Tests/EnvQueryTest_Distance.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

#define ENVQUERYTEST_DISTANCE_NAN_DETECTION 1

namespace 
{
	FORCEINLINE float CalcDistance3D(const FVector& PosA, const FVector& PosB)
	{
		return (PosB - PosA).Size();
	}

	FORCEINLINE float CalcDistance2D(const FVector& PosA, const FVector& PosB)
	{
		return (PosB - PosA).Size2D();
	}

	FORCEINLINE float CalcDistanceZ(const FVector& PosA, const FVector& PosB)
	{
		return PosB.Z - PosA.Z;
	}

	FORCEINLINE float CalcDistanceAbsoluteZ(const FVector& PosA, const FVector& PosB)
	{
		return FMath::Abs(PosB.Z - PosA.Z);
	}

	FORCEINLINE void CheckItemLocationForNaN(const FVector& ItemLocation, UObject* QueryOwner, int32 Index, uint8 TestMode)
	{
#if ENVQUERYTEST_DISTANCE_NAN_DETECTION
		ensureMsgf(!ItemLocation.ContainsNaN(), TEXT("EnvQueryTest_Distance NaN in ItemLocation with owner %s. X=%f,Y=%f,Z=%f. Index:%d, TesMode:%d"), *GetPathNameSafe(QueryOwner), ItemLocation.X, ItemLocation.Y, ItemLocation.Z, Index, TestMode);
#endif
	}

	FORCEINLINE void CheckContextLocationForNaN(const FVector& ContextLocation, UObject* QueryOwner, int32 Index, uint8 TestMode)
	{
#if ENVQUERYTEST_DISTANCE_NAN_DETECTION
		ensureMsgf(!ContextLocation.ContainsNaN(), TEXT("EnvQueryTest_Distance NaN in ContextLocations with owner %s. X=%f,Y=%f,Z=%f. Index:%d, TesMode:%d"), *GetPathNameSafe(QueryOwner), ContextLocation.X, ContextLocation.Y, ContextLocation.Z, Index, TestMode);
#endif
	}
}

UEnvQueryTest_EqsSelect::UEnvQueryTest_EqsSelect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
}

void UEnvQueryTest_EqsSelect::RunTest(FEnvQueryInstance& QueryInstance) const
{
	UObject* QueryOwner = QueryInstance.Owner.Get();
	if (QueryOwner == nullptr)
	{
		return;
	}

	FloatValueMin.BindData(QueryOwner, QueryInstance.QueryID);
	float MinThresholdValue = FloatValueMin.GetValue();

	FloatValueMax.BindData(QueryOwner, QueryInstance.QueryID);
	float MaxThresholdValue = FloatValueMax.GetValue();

	//============================================================
	
	// loop through all items
	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
	{
		//get actor 
		const AActor* ItemActor = GetItemActor(QueryInstance, It.GetIndex());
		if(!IsValid(ItemActor))
			It.ForceItemState(EEnvItemStatus::Failed);
		else
		{
			//cast to our target
			const auto eqs_selectActor = Cast<const A_EQS_SELECT>(ItemActor);
			if(!IsValid(eqs_selectActor))
				It.ForceItemState(EEnvItemStatus::Failed);
			else
			{
				DefaultValue.BindData(QueryOwner, QueryInstance.QueryID);
				ReferencePoint.BindData(QueryOwner, QueryInstance.QueryID);
				FloatValueMin.BindData(QueryOwner, QueryInstance.QueryID);
				FloatValueMax.BindData(QueryOwner, QueryInstance.QueryID);
		
				//get map & value. IF value is null then set it to default.
				//UE SHOULD BY DEFAULT IMPLEMENT -=SAFE=- FIND(key, default) and NOT give nullptr OR lat least WARN about it and NOT in their source code but in function description.
				//the way it is made now should be considered VIOLATION of good practices. 
				const auto map = eqs_selectActor->FloatMap;
		
				auto foundValue = map.Find(Value);
				auto value = DefaultValue.GetValue();
				if(foundValue!=nullptr)
					value = *foundValue;

				//substract ref value
				value -= ReferencePoint.GetValue();
				if(value<0)
					value*=-1;
		
				//get score (with extra steps for sake of UE convoluted code)
				It.SetScore(
					TestPurpose,
					FilterType,
					value,
					MinThresholdValue,
					MaxThresholdValue);
			}
		}
	}
}

FText UEnvQueryTest_EqsSelect::GetDescriptionTitle() const
{
	auto Fstring1 = Value.ToString();
	auto Fstring2 = DefaultValue.ToString();
	auto Fstring3 = ReferencePoint.ToString();

	auto Tchar1 = *Fstring1;
	auto Tchar2 = *Fstring2;
	auto Tchar3 = *Fstring3;
	
	return FText::FromString(FString::Printf(TEXT("Compare key: %s with defualt value of %s : to %s"), 
		Tchar1,
		Tchar2,
		Tchar3));
}

FText UEnvQueryTest_EqsSelect::GetDescriptionDetails() const
{
	return DescribeFloatTestParams();
}
