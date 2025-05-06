// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/MASWidgetController.h"

void UMASWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    AttributeSet = WCParams.AttributeSet;
}

void UMASWidgetController::BroadcastInitialValues()
{
}

void UMASWidgetController::BindCallbacksToDependancies()
{
}