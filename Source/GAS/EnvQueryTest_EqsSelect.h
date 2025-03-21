// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_EqsSelect.generated.h"

UCLASS()
class GAS_API UEnvQueryTest_EqsSelect : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()

	/** context */
	UPROPERTY(EditDefaultsOnly, Category=TestAttributes)
	FName Value;
	UPROPERTY(EditDefaultsOnly, Category=TestAttributes)
	FAIDataProviderFloatValue DefaultValue;
	UPROPERTY(EditDefaultsOnly, Category=TestAttributes)
	FAIDataProviderFloatValue ReferencePoint;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};


