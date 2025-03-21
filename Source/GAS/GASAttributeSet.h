// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UGASAttributeSet();
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	//================================================================--------------------------------
	
	//Current Health, when 0 we expect owner to die unless prevented by an ability. Capped by MaxHealth.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health);
	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	//================================================================

	// HealthMax is its own attribute since GameplayEffects may modify it
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health", ReplicatedUsing = OnRep_HealthMax)
	FGameplayAttributeData HealthMax;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HealthMax);
	UFUNCTION()
		virtual void OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax);
	
	//================================================================--------------------------------

	// Current Stamina, used to execute special abilities. Capped by StaminaMax.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina", ReplicatedUsing = OnRep_Stamina)
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Stamina);
	UFUNCTION()
		virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
	//================================================================

	// StaminaMax is its own attribute since GameplayEffects may modify it
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina", ReplicatedUsing = OnRep_StaminaMax)
	FGameplayAttributeData StaminaMax;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, StaminaMax);
	UFUNCTION()
		virtual void OnRep_StaminaMax(const FGameplayAttributeData& OldStaminaMax);
	//================================================================

	// Stamina regen rate will passively increase Stamina every second
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina", ReplicatedUsing = OnRep_StaminaRegen)
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, StaminaRegen);
	UFUNCTION()
		virtual void OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen);
	
	//================================================================--------------------------------

	// Ammo gained from ammo boxes. Used to fire from weapons
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Ammo", ReplicatedUsing = OnRep_Ammo)
	FGameplayAttributeData Ammo;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Ammo);
	UFUNCTION()
		virtual void OnRep_Ammo(const FGameplayAttributeData& OldAmmo);
	//================================================================

	// AmmoMax is its own attribute since GameplayEffects may modify it
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Ammo", ReplicatedUsing = OnRep_AmmoMax)
	FGameplayAttributeData AmmoMax;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AmmoMax);
	UFUNCTION()
		virtual void OnRep_AmmoMax(const FGameplayAttributeData& OldAmmoMax);
	
	//================================================================--------------------------------

	// Special used for custom abilities (eg. grandes, armor stacks etc.)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Special", ReplicatedUsing = OnRep_Special)
	FGameplayAttributeData Special;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Special);
	UFUNCTION()
		virtual void OnRep_Special(const FGameplayAttributeData& OldSpecial);
	//================================================================

	// SpecialMax is its own attribute since GameplayEffects may modify it
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Special", ReplicatedUsing = OnRep_SpecialMax)
	FGameplayAttributeData SpecialMax;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, SpecialMax);
	UFUNCTION()
		virtual void OnRep_SpecialMax(const FGameplayAttributeData& OldSpecialMax);

	//================================================================--------------------------------

	// By default punch damage. Here reused as damage multiplayer (weapon specific damage is multiplied by this value)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Other", ReplicatedUsing = OnRep_AttackPower)
		FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackPower);
	UFUNCTION()
		virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);
	//================================================================--------------------------------

	// MoveSpeed affects how fast characters can move. Used as proving ground for continuously changed attribute (meta attribute)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Other", ReplicatedUsing = OnRep_WalkingSpeed)
		FGameplayAttributeData WalkingSpeed;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, WalkingSpeed);
	UFUNCTION()
		virtual void OnRep_WalkingSpeed(const FGameplayAttributeData& OldWalkingSpeed);
};
