// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystem/MASPawnAttributeSet.h"
#include "MyAbilitySystem/Data/MASPawnAttributeInfo.h"
#include "MASGameplayTags.h"
#include "MASGlobalDefinitions.h"

UMASPawnAttributeSet::UMASPawnAttributeSet()
{
    
}

void UMASPawnAttributeSet::BeginPlay()
{
    Super::BeginPlay();
}

void UMASPawnAttributeSet::InitializeAttributes(UMASPawnAttributeInfo* AttributeInfo)
{
    FMASPawnAttribute PawnAttributes = AttributeInfo->PawnAttributes;
    RegisterAttribute(&Hull);
    RegisterAttribute(&Shield);
    RegisterAttribute(&Energy);
    RegisterAttribute(&Speed);
    RegisterAttribute(&MaxHull);
    RegisterAttribute(&HullRepairRate);
    RegisterAttribute(&MaxShield);
    RegisterAttribute(&ShieldRechargeRate);
    RegisterAttribute(&MaxEnergy);
    RegisterAttribute(&EnergyRechargeRate);
    RegisterAttribute(&MaxSpeed);
    RegisterAttribute(&Acceleration);
    RegisterAttribute(&AlignSpeed);
    RegisterAttribute(&SensorRange);
    RegisterAttribute(&TargetLockSpeed);
    RegisterAttribute(&AfterburnerPower);

    SetAttributeValue(PawnAttributes.Hull.AttributeTag, PawnAttributes.Hull.Value);
    SetAttributeValue(PawnAttributes.Shield.AttributeTag, PawnAttributes.Shield.Value);
    SetAttributeValue(PawnAttributes.Energy.AttributeTag, PawnAttributes.Energy.Value);
    SetAttributeValue(PawnAttributes.Speed.AttributeTag, PawnAttributes.Speed.Value);
    SetAttributeValue(PawnAttributes.MaxHull.AttributeTag, PawnAttributes.MaxHull.Value);
    SetAttributeValue(PawnAttributes.HullRepairRate.AttributeTag, PawnAttributes.HullRepairRate.Value);
    SetAttributeValue(PawnAttributes.MaxShield.AttributeTag, PawnAttributes.MaxShield.Value);
    SetAttributeValue(PawnAttributes.ShieldRechargeRate.AttributeTag, PawnAttributes.ShieldRechargeRate.Value);
    SetAttributeValue(PawnAttributes.MaxEnergy.AttributeTag, PawnAttributes.MaxEnergy.Value);
    SetAttributeValue(PawnAttributes.EnergyRechargeRate.AttributeTag, PawnAttributes.EnergyRechargeRate.Value);
    SetAttributeValue(PawnAttributes.MaxSpeed.AttributeTag, PawnAttributes.MaxSpeed.Value);
    SetAttributeValue(PawnAttributes.Acceleration.AttributeTag, PawnAttributes.Acceleration.Value);
    SetAttributeValue(PawnAttributes.AlignSpeed.AttributeTag, PawnAttributes.AlignSpeed.Value);
    SetAttributeValue(PawnAttributes.SensorRange.AttributeTag, PawnAttributes.SensorRange.Value);
    SetAttributeValue(PawnAttributes.TargetLockSpeed.AttributeTag, PawnAttributes.TargetLockSpeed.Value);
    SetAttributeValue(PawnAttributes.AfterburnerPower.AttributeTag, PawnAttributes.AfterburnerPower.Value);
}

