// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyAbilitySystem/MASAttributeSet.h"
#include "MASPawnAttributeSet.generated.h"

class UMASPawnAttributeInfo;

/**
 * 
 */
UCLASS()
class MASSTARGRAVE_API UMASPawnAttributeSet : public UMASAttributeSet
{
	GENERATED_BODY()

public:
	UMASPawnAttributeSet();

	void InitializeAttributes(UMASPawnAttributeInfo* AttributeInfo);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FMASAttribute Hull = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Hull, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute Shield = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Shield, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute Energy = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Energy, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute Speed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Speed, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute MaxHull = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxHull, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute HullRepairRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_HullRepairRate, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute MaxShield = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxShield, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute ShieldRechargeRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_ShieldRechargeRate, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute MaxEnergy = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxEnergy, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute EnergyRechargeRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_EnergyRechargeRate, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute MaxSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxSpeed, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute Acceleration = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Acceleration, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute AlignSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_AlignSpeed, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute SensorRange = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_SensorRange, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute TargetLockSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_TargetLockSpeed, 0.f);

	UPROPERTY(EditAnywhere)
	FMASAttribute AfterburnerPower = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_AfterburnerPower, 0.f);
};
