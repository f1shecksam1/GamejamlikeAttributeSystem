// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * MASGameplayTags is a class that manages gameplay tags for the MAS (My Ability System) framework.
 *
 * Singleton class that provides a centralized location for defining and managing gameplay tags used in the MAS framework.
 */
struct FMASGameplayTags
{
public:
	static const FMASGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Ship_Hull;
	FGameplayTag Attributes_Ship_Shield;
	FGameplayTag Attributes_Ship_Energy;
	FGameplayTag Attributes_Ship_Speed;
	FGameplayTag Attributes_Ship_MaxHull;
	FGameplayTag Attributes_Ship_HullRepairRate;
	FGameplayTag Attributes_Ship_MaxShield;
	FGameplayTag Attributes_Ship_ShieldRechargeRate;
	FGameplayTag Attributes_Ship_MaxEnergy;
	FGameplayTag Attributes_Ship_EnergyRechargeRate;
	FGameplayTag Attributes_Ship_MaxSpeed;
	FGameplayTag Attributes_Ship_Acceleration;
	FGameplayTag Attributes_Ship_AlignSpeed;
	FGameplayTag Attributes_Ship_SensorRange;
	FGameplayTag Attributes_Ship_TargetLockSpeed;
	FGameplayTag Attributes_Ship_AfterburnerPower;

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_LeftCtrl;
	FGameplayTag InputTag_LeftShift;
	FGameplayTag InputTag_LeftAlt;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

protected:
private:
	static FMASGameplayTags GameplayTags;
};
