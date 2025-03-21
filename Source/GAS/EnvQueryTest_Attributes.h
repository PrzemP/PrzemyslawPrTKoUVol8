// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_Attributes.generated.h"

UENUM()
namespace EEnvTestAttribute
{
	enum AttributeEnum
	{
		Health,
		HealthMax,
		
		Stamina,
		StaminaMax,
		StaminaRegen,
		
		Ammo,
		AmmoMax,
		
		Special,
		SpecialMax,
		
		AttackPower,
		WalkingSpeed
	};
}

UCLASS()
class GAS_API UEnvQueryTest_Attributes : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()
	
	/** testing mode */
	UPROPERTY(EditDefaultsOnly, Category=Attribute)
	TEnumAsByte<EEnvTestAttribute::AttributeEnum> AttributeEnumValue;
	
	UPROPERTY(EditDefaultsOnly, Category=Attribute)
	float ReferencePoint;
	
	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};
