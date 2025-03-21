// Copyright The Knights of Unity. All Rights Reserved.
// TKOU: team implementation

#include "GASAIBotController.h"

#include "GASCharacter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"


// Sets default values
AGASAIBotController::AGASAIBotController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGASAIBotController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGASAIBotController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AGASCharacter* BotPawn = Cast<AGASCharacter>(InPawn);
	if(BotPawn)
	{
		SetGenericTeamId(BotPawn->TeamID);
	}
}

// Called every frame
void AGASAIBotController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGASAIBotController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{

	const APawn* PossessedPawn = GetPawn();
	const FGenericTeamId OldID = GetGenericTeamId();
	Super::SetGenericTeamId(NewTeamID);
	if(NewTeamID != OldID)
	{
		TArray<UActorComponent*> PerceptionComponents;
		GetComponents(UAIPerceptionComponent::StaticClass(),PerceptionComponents);;

		for (UActorComponent* PerceptionActorComponent : PerceptionComponents)
		{
			if(UAIPerceptionComponent* Perception = Cast<UAIPerceptionComponent>(PerceptionActorComponent))
			{
				Perception->RequestStimuliListenerUpdate();
				Perception->ForgetAll();
			}
		}


	}
}

FGenericTeamId AGASAIBotController::GetGenericTeamId() const
{
	return Super::GetGenericTeamId();
}

bool AGASAIBotController::IsEnemy(const AActor *Other)
{
	return GetTeamAttitudeTowards(*Other) == ETeamAttitude::Hostile;
}

ETeamAttitude::Type AGASAIBotController::GetTeamAttitudeTowards(const AActor& Other) const
{
	//TKOU: no teams set, could be better to check game mode if it is deathmatch
	FGenericTeamId MyTeamID = GetGenericTeamId();
	if(MyTeamID == 0)
	{
		return ETeamAttitude::Hostile;
	}
	
	if (const AAIController* OtherController = Cast<AAIController>(&Other))
	{
		return Super::GetTeamAttitudeTowards(*OtherController);
	}
	if (const APawn* OtherPawn = Cast<APawn>(&Other))
	{
		
		return Super::GetTeamAttitudeTowards(*OtherPawn->GetController());
	}

	return ETeamAttitude::Neutral;
}