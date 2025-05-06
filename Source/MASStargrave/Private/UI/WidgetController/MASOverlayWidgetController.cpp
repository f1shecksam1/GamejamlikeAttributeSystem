// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/MASOverlayWidgetController.h"
#include "MyAbilitySystem/MASPawnAttributeSet.h"


void UMASOverlayWidgetController::BroadcastInitialValues()
{
    UMASAttributeSet* PawnAttributeSet = Cast<UMASPawnAttributeSet>(AttributeSet);

    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_Hull, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_Hull));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_Shield, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_Shield));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_Energy, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_Energy));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_Speed, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_Speed));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_MaxHull, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_MaxHull));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_MaxShield, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_MaxShield));
    OnAttributeChangedDelegate.Broadcast(FMASGameplayTags::Get().Attributes_Ship_MaxEnergy, PawnAttributeSet->GetAttributeValue(FMASGameplayTags::Get().Attributes_Ship_MaxEnergy));
}

void UMASOverlayWidgetController::BindCallbacksToDependancies()
{
    UMASAttributeSet* PawnAttributeSet = Cast<UMASPawnAttributeSet>(AttributeSet);

    PawnAttributeSet->OnAttributeChanged.AddDynamic(this, &UMASOverlayWidgetController::GetAttributeValueOnChanged);
}

void UMASOverlayWidgetController::GetAttributeValueOnChanged(FGameplayTag AttributeTag, float NewValue)
{
    OnAttributeChangedDelegate.Broadcast(AttributeTag, NewValue);
}

