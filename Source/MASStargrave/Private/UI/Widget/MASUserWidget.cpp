// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/MASUserWidget.h"

void UMASUserWidget::SetWidgetController(UObject* InWidgetController)
{
    WidgetController = InWidgetController;
    WidgetControllerSet();
}
