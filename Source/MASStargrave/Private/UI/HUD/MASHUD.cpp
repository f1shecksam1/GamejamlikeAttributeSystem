// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/MASHUD.h"
#include "UI/Widget/MASUserWidget.h"
#include "UI/WidgetController/MASOverlayWidgetController.h"

UMASOverlayWidgetController* AMASHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (OverlayWidgetController == nullptr)
    {
        OverlayWidgetController = NewObject<UMASOverlayWidgetController>(this, OverlayWidgetControllerClass);
        OverlayWidgetController->SetWidgetControllerParams(WCParams);
        OverlayWidgetController->BindCallbacksToDependancies();
    }
    return OverlayWidgetController;
}

void AMASHUD::InitOverlay(APlayerController* PC, APlayerState* PS,  UMASAttributeSet* AS)
{
    checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in %s. Please update the Blueprint class settings."), *GetName());
    checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set in %s. Please update the Blueprint class settings."), *GetName());

    UUserWidget* Widget = CreateWidget<UMASUserWidget>(GetWorld(), OverlayWidgetClass);
    OverlayWidget = Cast<UMASUserWidget>(Widget);

    const FWidgetControllerParams WCParams(PC, PS, AS);
    UMASOverlayWidgetController* WidgetController = GetOverlayWidgetController(WCParams);

    OverlayWidget->SetWidgetController(WidgetController);
    WidgetController->BroadcastInitialValues();
    Widget->AddToViewport();
}