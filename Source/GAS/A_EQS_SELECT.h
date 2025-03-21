// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_EQS_SELECT.generated.h"

// Code review: Naming should be consistent with other files and classes GAS...
// some folder structure should be introduced for c++ files
// blueprint names are also inconsistent like endlessWorldPlayerController - this file is in camel case instead of pascal
// we have multiple ThirdPerson folders and it variations, 


UCLASS()
class GAS_API A_EQS_SELECT : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	A_EQS_SELECT();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EQS_Select")
	FName Option;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EQS_Select")
	TMap<FName, float> FloatMap;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
