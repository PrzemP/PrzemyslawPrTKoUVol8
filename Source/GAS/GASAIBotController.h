// Copyright The Knights of Unity. All Rights Reserved.
// TKOU: team implementation

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GASAIBotController.generated.h"

UCLASS()
class GAS_API AGASAIBotController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGASAIBotController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;
	
	virtual FGenericTeamId GetGenericTeamId() const override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsEnemy(const AActor *Other);
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const;
};
