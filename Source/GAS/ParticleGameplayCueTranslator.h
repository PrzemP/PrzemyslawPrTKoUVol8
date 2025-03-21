// Copyright The Knights of Unity. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "GameplayCueManager.h"
#include "GameplayCueTranslator.h"
#include "ParticleGameplayCueTranslator.generated.h"

UCLASS()
class GAS_API UParticleGameplayCueTranslator : public UGameplayCueTranslator
{
	GENERATED_BODY()

	mutable int Value1 = 0;
	mutable int Value2 = 0;
	mutable int Value3 = 0;
	
public:
	virtual void GetTranslationNameSpawns(TArray<FGameplayCueTranslationNameSwap>& SwapList) const override
	{		
		{// OK; will build
			FGameplayCueTranslationNameSwap Temp;
			Temp.FromName = FName(TEXT("AC1"));
			Temp.ToNames.Add( FName(TEXT("AC2A")));
			Value1 = SwapList.Add(Temp);
		}
		{// OK; will build
			FGameplayCueTranslationNameSwap Temp;
			Temp.FromName = FName(TEXT("AC1"));
			Temp.ToNames.Add( FName(TEXT("AC2B")));
			Value2 = SwapList.Add(Temp);
		}

		// {// NOT OK; will NOT build
		// 	FGameplayCueTranslationNameSwap Temp;
		// 	Temp.FromName = FName(TEXT("AC1"));
		// 	Value1 = Temp.ToNames.Add( FName(TEXT("AC2A")));
		// 	Value2 = Temp.ToNames.Add( FName(TEXT("AC2B")));
		// 	SwapList.Add(Temp);
		// }
		
		// { //-=>NOT<=- OK; WILL compile, WILL build, -=WILL FREEZE EDITOR=- 
		// 	FGameplayCueTranslationNameSwap Temp;
		// 	Temp.FromName = FName(TEXT("AC3"));
		// 	Temp.ToNames.Add( FName(TEXT("AC3B")) );
		// 	Value1 = SwapList.Add(Temp);
		// }
		// {
		// 	FGameplayCueTranslationNameSwap Temp;
		// 	Temp.FromName = FName(TEXT("AC3B"));
		// 	Temp.ToNames.Add( FName(TEXT("AC3")) );
		// 	Value1 = SwapList.Add(Temp);
		// }

		// {// NOT OK; will NOT build
		// 	FGameplayCueTranslationNameSwap Temp;
		// 	Temp.FromName = FName(TEXT("AC4"));
		// 	Temp.ToNames.Add( FName(TEXT("AC4.AC4T1")) );
		// 	SwapList.Add(Temp);
		// }

		{// OK; will build
			FGameplayCueTranslationNameSwap Temp;
			Temp.FromName = FName(TEXT("AC5.AC5T2"));
			Temp.ToNames.Add( FName(TEXT("AC5")) );
			SwapList.Add(Temp);
		}

		// {// NOT OK; will NOT build
		// 	FGameplayCueTranslationNameSwap Temp;
		// 	Temp.FromName = FName(TEXT("AC6.AC6T3"));
		// 	Temp.ToNames.Add( FName(TEXT("AC6.AC6T4")) );
		// 	SwapList.Add(Temp);
		// }

		{// OK; will build
			FGameplayCueTranslationNameSwap Temp;
			Temp.FromName = FName(TEXT("AC5"));
			Temp.ToNames.Add( FName(TEXT("AC6")) );
			Value3 = SwapList.Add(Temp);
		}
	}
	virtual int32 GameplayCueToTranslationIndex(const FName& TagName, AActor* TargetActor, const FGameplayCueParameters& Parameters) const
	{
		if(TagName.IsEqual(FName(TEXT("GameplayCue.AC1"))))
			if(TargetActor->ActorHasTag(FName(TEXT("TR.A1"))))
				return Value1;
			else
				return Value2;

		if(TagName.IsEqual(FName(TEXT("AC5"))))
			return Value3;
		
		return -1;
	}
	virtual bool IsEnabled() const override { return true; }
	/*
Cmd: Log LogGameplayCueTranslator Verbose
LogGameplayCueTranslator                  Verbose       
Cmd: GameplayCue.BuildGameplayCueTranslator
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC2. Possible Parent Tag: GameplayCue.AC1
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5. Possible Parent Tag: GameplayCue.AC5.AC5T2
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5.AC5T2. Possible Parent Tag: GameplayCue.AC5.AC5T2.AC5T2
LogGameplayCueTranslator:    No tag match found, recursing...
LogGameplayCueTranslator:    No tag match found after recursing. Dead end.
LogStats: UGameplayCueManager::InitializeEditorObjectLibrary -  0.005 s
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC2. Possible Parent Tag: GameplayCue.AC1
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5. Possible Parent Tag: GameplayCue.AC5.AC5T2
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5.AC5T2. Possible Parent Tag: GameplayCue.AC5.AC5T2.AC5T2
LogGameplayCueTranslator:    No tag match found, recursing...
LogGameplayCueTranslator:    No tag match found after recursing. Dead end.
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC2. Possible Parent Tag: GameplayCue.AC1
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5. Possible Parent Tag: GameplayCue.AC5.AC5T2
LogGameplayCueTranslator:    Matches real tags! Adding to translation tree
LogGameplayCueTranslator: Found possible expanded tag. Original Child Tag: GameplayCue.AC5.AC5T2. Possible Parent Tag: GameplayCue.AC5.AC5T2.AC5T2
LogGameplayCueTranslator:    No tag match found, recursing...
LogGameplayCueTranslator:    No tag match found after recursing. Dead end.
Cmd: GameplayCue.PrintGameplayCueTranslator
LogGameplayCueTranslator: Display: Printing GameplayCue Translation Table. * means tag is not created but could be.
LogGameplayCueTranslator: Display: GameplayCue.AC1 
LogGameplayCueTranslator: Display:  -> GameplayCue.AC2 [Default__ParticleGameplayCueTranslator]
LogGameplayCueTranslator: Display: GameplayCue.AC5.AC5T2 
LogGameplayCueTranslator: Display:  -> GameplayCue.AC5 [Default__ParticleGameplayCueTranslator]
LogGameplayCueTranslator: Display: Total Number of Translations with valid tags: 2
LogGameplayCueTranslator: Display: Total Number of Translations without  valid tags: 0 (theoretical translations)
	 */
};
