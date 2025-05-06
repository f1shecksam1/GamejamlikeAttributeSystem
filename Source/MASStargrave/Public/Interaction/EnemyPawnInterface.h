// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyPawnInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyPawnInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MASSTARGRAVE_API IEnemyPawnInterface
{
	GENERATED_BODY()

public:
	virtual void HighLightActor() = 0;
	virtual void UnhighLightActor() = 0;
};
