// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GASAbilitySystemComponent.h"

UENUM(BlueprintType)
enum class EGASAbilityInputID : uint8 {
	None, Confirm, Cancel, Punch, Sprint, Fire, Realod, Nade, Special
};
