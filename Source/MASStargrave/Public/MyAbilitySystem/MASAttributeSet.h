// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "MASGlobalDefinitions.h"
#include "MASAttributeSet.generated.h"

class UMASAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedSignature, FGameplayTag, AttributeTag, float, NewValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MASSTARGRAVE_API UMASAttributeSet : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMASAttributeSet();

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChangedSignature OnAttributeChanged;

	UFUNCTION(BlueprintCallable)
	float GetAttributeValue(const FGameplayTag& Tag) const;

	UFUNCTION(BlueprintCallable)
	void SetAttributeValue(const FGameplayTag& Tag, float NewValue);

	UFUNCTION(BlueprintCallable)
	void AddToAttributeValue(const FGameplayTag& Tag, float DeltaValue);

protected:
	virtual void BeginPlay() override;

	TArray<FMASAttribute*> Attributes;
	
	void RegisterAttribute(FMASAttribute* Attribute);
	FMASAttribute* FindAttribute(const FGameplayTag& Tag);
};
