// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystem/MASAttributeSet.h"

UMASAttributeSet::UMASAttributeSet()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UMASAttributeSet::GetAttributeValue(const FGameplayTag& Tag) const
{
	for (const FMASAttribute* Attr : Attributes)
	{
		if (Attr && Attr->AttributeTag == Tag)
		{
			return Attr->Value;
		}
	}
	return 0.f;
}

void UMASAttributeSet::SetAttributeValue(const FGameplayTag& Tag, float NewValue)
{
	if (FMASAttribute* Attr = FindAttribute(Tag))
	{
		Attr->Value = NewValue;
		OnAttributeChanged.Broadcast(Tag, NewValue);
	}
}

void UMASAttributeSet::AddToAttributeValue(const FGameplayTag& Tag, float DeltaValue)
{
	if (FMASAttribute* Attr = FindAttribute(Tag))
	{
		Attr->Value += DeltaValue;
		OnAttributeChanged.Broadcast(Tag, Attr->Value);
	}
}

void UMASAttributeSet::BeginPlay()
{
	Super::BeginPlay();
	
}

void UMASAttributeSet::RegisterAttribute(FMASAttribute* Attribute)
{
	if (Attribute)
	{
		Attributes.Add(Attribute);
	}
}

FMASAttribute* UMASAttributeSet::FindAttribute(const FGameplayTag& Tag)
{
	for (FMASAttribute* Attribute : Attributes)
	{
		if (Attribute && Attribute->AttributeTag == Tag)
		{
			return Attribute;
		}
	}
	return nullptr;
}
