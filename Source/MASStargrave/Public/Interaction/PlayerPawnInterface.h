// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerPawnInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPlayerPawnInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MASSTARGRAVE_API IPlayerPawnInterface
{
	GENERATED_BODY()

public:

public:
	virtual void SetSpringArmLength(float CurrentTargetArmLength) = 0;
	virtual float GetSpringArmLength() = 0;
	virtual void SetShipDestination(const FVector& Destination) = 0;
};
