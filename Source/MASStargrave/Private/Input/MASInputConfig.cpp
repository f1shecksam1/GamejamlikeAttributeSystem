// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/MASInputConfig.h"

const UInputAction* UMASInputConfig::FindInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFoudd) const
{
    for (const FMASInputAction& Action : InputActions)
    {
        if (Action.InputAction && Action.InputTag == InputTag)
        {
            return Action.InputAction;
        }
    }

    if (bLogNotFoudd)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can't find InputActionForInputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
    }

    return nullptr;
}
