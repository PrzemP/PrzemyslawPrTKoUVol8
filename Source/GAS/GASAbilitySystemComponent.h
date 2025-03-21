// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GASAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UGASAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class GAS_API UGASAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	const UAttributeSet* UGASAbilitySystemComponent::MyGetAttributeSet(TSubclassOf<UAttributeSet> AttributeSetClass) const
	{
		// get the attribute set
		const UAttributeSet* AttributeSet = GetAttributeSubobject(AttributeSetClass);

		// return the pointer
		return AttributeSet;
	}
	
};
