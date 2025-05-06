// Fill out your copyright notice in the Description page of Project Settings.


#include "MASGameplayTags.h"
#include "GameplayTagsManager.h"

FMASGameplayTags FMASGameplayTags::GameplayTags;

void FMASGameplayTags::InitializeNativeGameplayTags()
{
    /*
   * Attributes Tags
   */


    GameplayTags.Attributes_Ship_Hull = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.Hull"), FString("Represents the hull integrity of the ship."));
    GameplayTags.Attributes_Ship_Shield = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.Shield"), FString("Represents the shield strength of the ship."));
    GameplayTags.Attributes_Ship_Energy = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.Energy"), FString("Represents the energy level of the ship."));
    GameplayTags.Attributes_Ship_MaxHull = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.MaxHull"), FString("Represents the maximum hull capacity of the ship."));
    GameplayTags.Attributes_Ship_HullRepairRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.HullRepairRate"), FString("Represents the hull repair rate of the ship."));
    GameplayTags.Attributes_Ship_MaxShield = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.MaxShield"), FString("Represents the maximum shield capacity of the ship."));
    GameplayTags.Attributes_Ship_ShieldRechargeRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.ShieldRechargeRate"), FString("Represents the shield recharge rate of the ship."));
    GameplayTags.Attributes_Ship_MaxEnergy = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.MaxEnergy"), FString("Represents the maximum energy capacity of the ship."));
    GameplayTags.Attributes_Ship_EnergyRechargeRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.EnergyRechargeRate"), FString("Represents the energy recharge rate of the ship."));
    GameplayTags.Attributes_Ship_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.Speed"), FString("Represents the target speed of the ship."));
    GameplayTags.Attributes_Ship_MaxSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.MaxSpeed"), FString("Represents the maximum speed of the ship."));
    GameplayTags.Attributes_Ship_Acceleration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.Acceleration"), FString("Represents the acceleration of the ship."));
    GameplayTags.Attributes_Ship_AlignSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.AlignSpeed"), FString("Represents the alignment speed of the ship."));
    GameplayTags.Attributes_Ship_SensorRange = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.SensorRange"), FString("Represents the sensor range of the ship."));
    GameplayTags.Attributes_Ship_TargetLockSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.TargetLockSpeed"), FString("Represents the target lock speed of the ship."));
    GameplayTags.Attributes_Ship_AfterburnerPower = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Ship.AfterburnerPower"), FString("Represents the afterburner power of the ship."));

    
    /*
    * Input Tags
    */
    GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString("Left Mouse Button"));
    GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString("Right Mouse Button"));
    GameplayTags.InputTag_LeftCtrl = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LeftCtrl"), FString("Left Control Key"));
    GameplayTags.InputTag_LeftShift = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LeftShift"), FString("Left Shift Key"));
    GameplayTags.InputTag_LeftAlt = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LeftAlt"), FString("Left Alt Key"));
    GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString("1 key"));
    GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString("2 key"));
    GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString("3 key"));
    GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString("4 key"));
}
