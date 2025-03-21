// Copyright The Knights of Unity. All Rights Reserved.


#include "GASAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UGASAttributeSet::UGASAttributeSet() {

}

//clamp current values changes to Max handled in PostGameplayEffectExecute since they modify different attribute
void UGASAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();


	if(Attribute == GetHealthAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, HealthMax.GetCurrentValue());
	if(Attribute == GetHealthMaxAttribute())
		if(NewValue<Health.GetCurrentValue())
			AbilityComp->ApplyModToAttribute(GetHealthAttribute(), EGameplayModOp::Override, NewValue);

	if(Attribute == GetStaminaAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, StaminaMax.GetCurrentValue());
	if(Attribute == GetStaminaMaxAttribute())
		if(NewValue<Stamina.GetCurrentValue())
			AbilityComp->ApplyModToAttribute(GetStaminaAttribute(), EGameplayModOp::Override, NewValue);
	
	if(Attribute == GetAmmoAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, AmmoMax.GetCurrentValue());
	if(Attribute == GetAmmoMaxAttribute())
		if(NewValue<Ammo.GetCurrentValue())
			AbilityComp->ApplyModToAttribute(GetAmmoAttribute(), EGameplayModOp::Override, NewValue);

	if(Attribute == GetSpecialAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, SpecialMax.GetCurrentValue());
	if(Attribute == GetSpecialMaxAttribute())
		if(NewValue<Special.GetCurrentValue())
			AbilityComp->ApplyModToAttribute(GetSpecialAttribute(), EGameplayModOp::Override, NewValue);

	if(Attribute == GetAttackPowerAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 0, 1000);
	if(Attribute == GetWalkingSpeedAttribute())
		NewValue = FMath::Clamp<float>(NewValue, 150, 10000);
}

//todo: add functionality
void UGASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, StaminaMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, StaminaRegen, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Ammo, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AmmoMax, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Special, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, SpecialMax, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, WalkingSpeed, COND_None, REPNOTIFY_Always);
}

void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Health, OldHealth);
}

void UGASAttributeSet::OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, HealthMax, OldHealthMax);
}

void UGASAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Stamina, OldStamina);
}

void UGASAttributeSet::OnRep_StaminaMax(const FGameplayAttributeData& OldStaminaMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, StaminaMax, OldStaminaMax);
}

void UGASAttributeSet::OnRep_StaminaRegen(const FGameplayAttributeData& OldStaminaRegen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, StaminaRegen, OldStaminaRegen);
}

void UGASAttributeSet::OnRep_Ammo(const FGameplayAttributeData& OldAmmo)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Ammo, OldAmmo);
}

void UGASAttributeSet::OnRep_AmmoMax(const FGameplayAttributeData& OldAmmoMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AmmoMax, OldAmmoMax);
}

void UGASAttributeSet::OnRep_Special(const FGameplayAttributeData& OldSpecial)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Special, OldSpecial);
}

void UGASAttributeSet::OnRep_SpecialMax(const FGameplayAttributeData& OldSpecialMax)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, SpecialMax, OldSpecialMax);
}

void UGASAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackPower, OldAttackPower);
}

void UGASAttributeSet::OnRep_WalkingSpeed(const FGameplayAttributeData& OldWalkingSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, WalkingSpeed, OldWalkingSpeed);
}
