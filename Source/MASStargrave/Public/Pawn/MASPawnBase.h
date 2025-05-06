// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interaction/MyAbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "MASPawnBase.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UChildActorComponent;
class UMASMovementComponent;
class UMASPawnAttributeSet;
class UMASPawnAttributeInfo;

UCLASS()
class MASSTARGRAVE_API AMASPawnBase : public APawn , public IMyAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMASPawnBase();

	UPROPERTY(EditAnywhere, Category = "Attributes")
	TObjectPtr<UMASAttributeSet> AttributeSet;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	virtual UMASAttributeSet* GetMASAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UBoxComponent> ShipCollision;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> ShipMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UMASMovementComponent> MovementComponent;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UChildActorComponent> TurretActor1;

	UPROPERTY(EditAnywhere, Category = "Combat")
	FName TurretSocket1Name = "TurretSocket1";

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TObjectPtr<UMASPawnAttributeInfo> PawnAttributeInfo;

	virtual void InitAbilityActorInfo();

	void InitializeAttributes();

	UFUNCTION(BlueprintCallable)
	void BindAttributeValue(FGameplayTag AttributeTag, float Value);
};
