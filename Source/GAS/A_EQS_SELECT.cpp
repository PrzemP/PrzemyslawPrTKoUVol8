// Copyright The Knights of Unity. All Rights Reserved.


#include "A_EQS_SELECT.h"

// Sets default values
A_EQS_SELECT::A_EQS_SELECT()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void A_EQS_SELECT::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(10);
}

// Called every frame
void A_EQS_SELECT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

