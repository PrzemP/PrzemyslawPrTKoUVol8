// Copyright The Knights of Unity. All Rights Reserved.


#include "EnvQueryTest_Attributes.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GASAbilitySystemComponent.h"
#include "GASAttributeSet.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_ActorBase.h"

class IAbilitySystemInterface;

UEnvQueryTest_Attributes::UEnvQueryTest_Attributes(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer), AttributeEnumValue(), ReferencePoint(0)
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_ActorBase::StaticClass();
}

void UEnvQueryTest_Attributes::RunTest(FEnvQueryInstance& QueryInstance) const
{
	Super::RunTest(QueryInstance);
	UObject* QueryOwner = QueryInstance.Owner.Get();
	if (QueryOwner == nullptr)
	{
		return;
	}
	FloatValueMin.BindData(QueryOwner, QueryInstance.QueryID);
	const float MinThresholdValue = FloatValueMin.GetValue();

	FloatValueMax.BindData(QueryOwner, QueryInstance.QueryID);
	const float MaxThresholdValue = FloatValueMax.GetValue();
	
	// loop through all items
	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
	{
		const AActor* ItemActor = GetItemActor(QueryInstance, It.GetIndex());
		if (const IAbilitySystemInterface* GameplayTagAssetInterface = Cast<const IAbilitySystemInterface>(ItemActor))
		{
			//const UGASAttributeSet* set =  Cast<const UGASAttributeSet>(GameplayTagAssetInterface->GetAbilitySystemComponent()->GetAttributeSet(UGASAttributeSet::StaticClass()));
			auto cmp =   Cast<const UGASAbilitySystemComponent>(GameplayTagAssetInterface->GetAbilitySystemComponent());
			auto set = Cast<const UGASAttributeSet>(cmp->MyGetAttributeSet(UGASAttributeSet::StaticClass()));
			
			switch (AttributeEnumValue)
			{
			case EEnvTestAttribute::Health:
				{It.SetScore(TestPurpose, FilterType,(set->Health.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::HealthMax:
				{It.SetScore(TestPurpose, FilterType,(set->HealthMax.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
				
			case EEnvTestAttribute::Stamina:
				{It.SetScore(TestPurpose, FilterType,(set->Stamina.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::StaminaMax:
				{It.SetScore(TestPurpose, FilterType,(set->StaminaMax.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::StaminaRegen:
				{It.SetScore(TestPurpose, FilterType,(set->StaminaRegen.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
				
			case EEnvTestAttribute::Ammo:
				{It.SetScore(TestPurpose, FilterType,(set->Ammo.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::AmmoMax:
				{It.SetScore(TestPurpose, FilterType,(set->AmmoMax.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;

			case EEnvTestAttribute::Special:
				{It.SetScore(TestPurpose, FilterType,(set->Special.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::SpecialMax:
				{It.SetScore(TestPurpose, FilterType,(set->SpecialMax.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;

			case EEnvTestAttribute::AttackPower:
				{It.SetScore(TestPurpose, FilterType,(set->AttackPower.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			case EEnvTestAttribute::WalkingSpeed:
				{It.SetScore(TestPurpose, FilterType,(set->WalkingSpeed.GetCurrentValue()-ReferencePoint), MinThresholdValue, MaxThresholdValue);}
				break;
			default:
				checkNoEntry();
				return;
			}
		}
		else 
		{
			It.ForceItemState(EEnvItemStatus::Failed);
		}
	}
}

FText UEnvQueryTest_Attributes::GetDescriptionTitle() const
{
	return Super::GetDescriptionTitle();
}

FText UEnvQueryTest_Attributes::GetDescriptionDetails() const
{
	return Super::GetDescriptionDetails();
}
