// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/MASWidgetController.h"
#include "GameplayTagContainer.h"
#include "MASOverlayWidgetController.generated.h"

class UMASUserWidget;

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UMASUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D *Image = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMASOnAttributeChangedSignature, FGameplayTag, AttributeTag, float, NewValue);


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MASSTARGRAVE_API UMASOverlayWidgetController : public UMASWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependancies() override;

	UPROPERTY(BlueprintAssignable, Category = "MAS|Attributes")
	FMASOnAttributeChangedSignature OnAttributeChangedDelegate;

	UFUNCTION(BlueprintCallable, Category = "MAS|Attributes")
	void GetAttributeValueOnChanged(FGameplayTag AttributeTag, float NewValue);
};
