// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MASGlobalDefinitions.h"
#include "MASPawnAttributeInfo.generated.h"

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API UMASPawnAttributeInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FMASPawnAttribute PawnAttributes;
	
};
