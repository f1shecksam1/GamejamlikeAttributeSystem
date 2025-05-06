// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystem/Data/MASAttributeInfo.h"

FMASAttributeInfoStruct UMASAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
    for (const FMASAttributeInfoStruct& AttributeInfo : AttributeInformation)
    {
        if (AttributeInfo.AttributeTag.MatchesTag(AttributeTag))
        {
            return AttributeInfo;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Warning, TEXT("AttributeInfo not found for tag: %s"), *AttributeTag.ToString());
    }

    return FMASAttributeInfoStruct();
}
