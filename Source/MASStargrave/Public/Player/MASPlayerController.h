// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MASGlobalDefinitions.h"
#include "GameplayTagContainer.h"
#include "MASPlayerController.generated.h"

class UInputMappingContext;
struct FInputActionValue;
class IEnemyPawnInterface;
class IPlayerPawnInterface;
class UMASInputConfig;
class UInputAction;

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API AMASPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMASPlayerController();

	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MASContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MouseXYAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MouseScrollAction;

	void LeftAltHeld();
	void LeftAltReleased();
	void LMBPressed();
	void RMBPressed();
	void MouseXY(const FInputActionValue& Value);
	void MouseScroll(const FInputActionValue& Value);

	FVector HorizontalIntersection;
	FVector VerticalIntersection;

	void GetHorizontalIntersection();
	void GetVerticalIntersection();

	UPROPERTY(EditAnywhere, Category = "InputValues")
	float CameraRotationSpeed = 1.f;

	UPROPERTY(EditAnywhere, Category = "InputValues")
	float CameraScrollSpeed = 1.f;

	UPROPERTY(EditAnywhere, Category = "InputValues")
	float CameraZoomMin = 1000.f;

	UPROPERTY(EditAnywhere, Category = "InputValues")
	float CameraZoomMax = 5000.f;

	void CursorTrace();
	TScriptInterface<IEnemyPawnInterface> LastActor;
	TScriptInterface<IEnemyPawnInterface> ThisActor;
	TScriptInterface<IPlayerPawnInterface> PlayerShip;
	FHitResult CursorHit;

	EControllerSelectionState ControllerSelectionState;
	EControllerIntersectionState ControllerIntersectionState;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UMASInputConfig> InputConfig;

	bool bTargeting = false;
};
