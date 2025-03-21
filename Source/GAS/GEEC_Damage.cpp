// Copyright The Knights of Unity. All Rights Reserved.


#include "GEEC_Damage.h"

#include "GASAbilitySystemComponent.h"
#include "GASAttributeSet.h"

struct GEEC_Damage_Target_Struct
{
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(HealthMax);

	DECLARE_ATTRIBUTE_CAPTUREDEF(Stamina);
	DECLARE_ATTRIBUTE_CAPTUREDEF(StaminaMax);
	DECLARE_ATTRIBUTE_CAPTUREDEF(StaminaRegen);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(Ammo);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AmmoMax);

	DECLARE_ATTRIBUTE_CAPTUREDEF(Special);
	DECLARE_ATTRIBUTE_CAPTUREDEF(SpecialMax);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(WalkingSpeed);
	
	GEEC_Damage_Target_Struct()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Health, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, HealthMax, Target,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Stamina, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, StaminaMax, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, StaminaRegen, Target,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Ammo, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, AmmoMax, Target,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Special, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, SpecialMax, Target,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, AttackPower, Target,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, WalkingSpeed, Target,false);
	}
};

struct GEEC_Damage_Source_Struct
{
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(HealthMax);

	DECLARE_ATTRIBUTE_CAPTUREDEF(Stamina);
	DECLARE_ATTRIBUTE_CAPTUREDEF(StaminaMax);
	DECLARE_ATTRIBUTE_CAPTUREDEF(StaminaRegen);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(Ammo);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AmmoMax);

	DECLARE_ATTRIBUTE_CAPTUREDEF(Special);
	DECLARE_ATTRIBUTE_CAPTUREDEF(SpecialMax);
	
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(WalkingSpeed);
	
	GEEC_Damage_Source_Struct()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Health, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, HealthMax, Source,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Stamina, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, StaminaMax, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, StaminaRegen, Source,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Ammo, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, AmmoMax, Source,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, Special, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, SpecialMax, Source,false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, AttackPower, Source,false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UGASAttributeSet, WalkingSpeed, Source,false);
	}
};

static GEEC_Damage_Target_Struct& Get_GEEC_Damage_Target_Struct()
{
	static GEEC_Damage_Target_Struct GEEC_Damage_Target_Struct;
	return GEEC_Damage_Target_Struct;
}

static GEEC_Damage_Source_Struct&  Get_GEEC_Damage_Source_Struct()
{
	static GEEC_Damage_Source_Struct GEEC_Damage_Source_Struct;
	return GEEC_Damage_Source_Struct;
}

UGEEC_Damage::UGEEC_Damage()
{
	{
		GEEC_Damage_Target_Struct GEEC_Damage_Struct = Get_GEEC_Damage_Target_Struct();
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.HealthDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.HealthMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaMaxDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaRegenDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AmmoDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AmmoMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.SpecialDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.SpecialMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AttackPowerDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.WalkingSpeedDef);
	}
	{
		GEEC_Damage_Source_Struct GEEC_Damage_Struct = Get_GEEC_Damage_Source_Struct();
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.HealthDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.HealthMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaMaxDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.StaminaRegenDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AmmoDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AmmoMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.SpecialDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.SpecialMaxDef);
		
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.AttackPowerDef);
		RelevantAttributesToCapture.Add(GEEC_Damage_Struct.WalkingSpeedDef);
	}
}

void UGEEC_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	//get refs
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->GetAvatarActor() : nullptr;
	AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->GetAvatarActor() : nullptr;

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	//get flags
	bool IsSourceArmored = SourceTags->HasTag(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored")));
	bool IsTargetArmored = TargetTags->HasTag(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored")));
	bool IsSourceLight =   SourceTags->HasTag(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light")));
	bool IsTargetLight =   TargetTags->HasTag(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light")));
	bool IsThisPunch = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GA.Punch")), false, 0) == 1;
	float LifeSteal =  Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GA.LifeSteal")), false, 0);
	
	//override flags if needed 
	if(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored.Source")), false, 0) != 0)IsSourceArmored = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored.Source")), false, 0) == 1;
	if(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored.Target")), false, 0) != 0)IsTargetArmored = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Armored.Target")), false, 0) == 1;
	if(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light.Source"))  , false, 0) != 0)IsSourceLight =   Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light.Source"))  , false, 0) == 1;
	if(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light.Target"))  , false, 0) != 0)IsTargetLight =   Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Type.Light.Target"))  , false, 0) == 1;

	//================================================================================================================== actuall calc
	//this code uses example marine to explain what where and why is going on.
	//Example marine can attack on distance and will punch at melee. Additionally each attack has a chance to trigger with randomized value of LifeSteal

	//get attack power. this is defined either in GE or dynamically by AssignTagSetByCallerMagnitude (lookup GA_Punch)
	float BaseDamage =	0.0;
	BaseDamage = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("GE.Damage.BaseDamage")), true, 1);
	
	//get attack power. this is defined as attribute for each avatar. (so you can have like weak marine, elite marine, etc). used instead of curve table and skill level.
	float AttackPower = 0.0;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().AttackPowerDef, EvaluationParameters, AttackPower);

	//calculate initial damage dealt to target
	float DamageDealt = BaseDamage * AttackPower;
	//initiall damage (or heal) dealt to source
	float DamageBack = 0.0;
	if(IsThisPunch)
	{
		{
			//increase damage based on difference in  your 'size'
			float HealthMaxSource = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().HealthMaxDef, EvaluationParameters, HealthMaxSource);
			float HealthMaxTarget = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().HealthMaxDef, EvaluationParameters, HealthMaxTarget);
			DamageDealt *= (HealthMaxSource/HealthMaxTarget);
		}
		
		if(IsSourceArmored && !IsTargetArmored)
		{
			float Armor = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().SpecialDef, EvaluationParameters, Armor);
			//increase damage up to 2 times (assuming armor value (0..1>)
			DamageDealt *= 1+Armor;
		}
		
		if(!IsSourceArmored && IsTargetArmored)
		{
			float Armor = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().SpecialDef, EvaluationParameters, Armor);
			//how much damage is dealt to NOT reflected
			float DamageModified = DamageDealt/(1+Armor);
			//reflected damage (goes BACK to source)
			DamageBack = DamageDealt-DamageModified;
			//update DamageDealt
			DamageDealt = DamageModified;
		}
		
		if(IsSourceArmored && IsTargetArmored)
		{
			float ArmorSource = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().SpecialDef, EvaluationParameters, ArmorSource);
			float ArmoTarget = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().SpecialDef, EvaluationParameters, ArmoTarget);
			//get resulting armor for calc
			float resultArmor = (ArmorSource+1)/(ArmoTarget+1);
			
			//how much damage is dealt to NOT reflected
			float DamageModified = DamageDealt*resultArmor;
			//IF there IS reflected damage, THEN it goes BACK to source.
			if(resultArmor<0)
				DamageBack = DamageDealt-DamageModified;
			//update DamageDealt
			DamageDealt = DamageModified;
		}
	}
	else
	{
		if(IsTargetArmored)
		{
			float Armor = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().SpecialDef, EvaluationParameters, Armor);
			//in ranged attacks we do NOT reflect damage back to owner
			DamageDealt /= 1+Armor;
		}
	}
	
	if(LifeSteal != 0)
	{
		
		//GIVE relevant amount of life BACK to source.
		//NOTE: it means that attacks on tartget with armor value 1 with LifeSteal 1 will NOT harm us since damage reflected AND life stolen nullify each other.
		DamageBack -=  DamageDealt*LifeSteal;

		{
			float HealthMaxSource = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().HealthMaxDef, EvaluationParameters, HealthMaxSource);
			float HealthSource = 0.0;
			ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Source_Struct().HealthDef, EvaluationParameters, HealthSource);
			DamageBack = FMath::Clamp(DamageBack,(HealthSource-HealthMaxSource),HealthSource);
		}
		
		UGameplayEffect* GELifesteal = NewObject<UGameplayEffect>(GetTransientPackage(), FName(TEXT("Lifesteal")));
		GELifesteal->DurationPolicy = EGameplayEffectDurationType::Instant;

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f = FloatVariable"), DamageBack));
		
		int32 Idx = GELifesteal->Modifiers.Num();
		GELifesteal->Modifiers.SetNum(Idx + 1);
		FGameplayModifierInfo& Info = GELifesteal->Modifiers[Idx];
		Info.ModifierMagnitude = FScalableFloat(-DamageBack);
		Info.ModifierOp = EGameplayModOp::Additive;
		Info.Attribute = UGASAttributeSet::GetHealthAttribute();
		
		SourceAbilitySystemComponent->ApplyGameplayEffectToSelf(GELifesteal, 1.0f, SourceAbilitySystemComponent->MakeEffectContext());
	}

	//================================================================================================================== apply damage to target and IF necessary to source.
	//clamp effects 
	{
		float HealthMaxTarget = 0.0;
		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().HealthMaxDef, EvaluationParameters, HealthMaxTarget);
		float HealthTarget = 0.0;
		ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(Get_GEEC_Damage_Target_Struct().HealthDef, EvaluationParameters, HealthTarget);
		DamageDealt = FMath::Clamp(DamageDealt,(HealthTarget-HealthMaxTarget),HealthTarget);
	}
	//return effects
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Get_GEEC_Damage_Target_Struct().HealthProperty, EGameplayModOp::Additive, -DamageDealt));
	//OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(Get_GEEC_Damage_Source_Struct().HealthProperty, EGameplayModOp::Additive, -DamageBack));
}
