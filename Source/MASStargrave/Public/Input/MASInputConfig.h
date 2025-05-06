// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "MASInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FMASInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API UMASInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	const UInputAction* FindInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFoudd = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FMASInputAction> InputActions;
};
