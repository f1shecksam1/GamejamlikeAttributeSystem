// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MASAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API UMASAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UMASAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
	
};
