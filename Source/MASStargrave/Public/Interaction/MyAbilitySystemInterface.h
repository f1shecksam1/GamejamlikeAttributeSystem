// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyAbilitySystemInterface.generated.h"

class UMASAttributeSet;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyAbilitySystemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MASSTARGRAVE_API IMyAbilitySystemInterface
{
	GENERATED_BODY()

public:
	virtual UMASAttributeSet* GetMASAttributeSet() const = 0;
};
