// Fill out your copyright notice in the Description page of Project Settings.


#include "MASAssetManager.h"
#include "MASGameplayTags.h"

UMASAssetManager& UMASAssetManager::Get()
{
    // TODO: Insert return statement here
    // !Done

    check(GEngine);
    UMASAssetManager* MASAssetManager = Cast<UMASAssetManager>(GEngine->AssetManager);
    return *MASAssetManager;
}

void UMASAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    // TODO: Initialize native gameplay tags
    FMASGameplayTags::InitializeNativeGameplayTags();
}


