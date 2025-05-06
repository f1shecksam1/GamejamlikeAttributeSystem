// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MASHUD.generated.h"

class UMASAttributeSet;
class UMASOverlayWidgetController;
class UMASUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API AMASHUD : public AHUD
{
	GENERATED_BODY()
public:
	UMASOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UMASAttributeSet* AS);

private:
	UPROPERTY()
	TObjectPtr<UMASUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMASUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UMASOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMASOverlayWidgetController> OverlayWidgetControllerClass;
	
};
