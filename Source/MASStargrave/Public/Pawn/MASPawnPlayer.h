// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/MASPawnBase.h"
#include "Interaction/PlayerPawnInterface.h"
#include "MASPawnPlayer.generated.h"

/**
 *
 */
UCLASS()
class MASSTARGRAVE_API AMASPawnPlayer : public AMASPawnBase, public IPlayerPawnInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMASPawnPlayer();

	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* CameraComponent;

	virtual void SetSpringArmLength(float CurrentTargetArmLength) override;
	virtual float GetSpringArmLength() override;
	virtual void SetShipDestination(const FVector& Destination) override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
