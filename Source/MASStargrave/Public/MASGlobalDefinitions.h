// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MASGameplayTags.h"
#include "MASGlobalDefinitions.generated.h"

UENUM(BlueprintType)
enum class EShipControlMode : uint8
{
	AutomaticMode UMETA(DisplayName = "AutomaticMode"),
	ManuelMode UMETA(DisplayName = "ManuelMode")
};

UENUM(BlueprintType)
enum class EShipAutomaticMovementState : uint8
{
	Orbit UMETA(DisplayName = "Orbit"),
	Fallow UMETA(DisplayName = "Fallow")
};

UENUM(BlueprintType)
enum class EControllerSelectionState : uint8
{
	DefaultMode UMETA(DisplayName = "DefaultMode"),
	IntersectionMode UMETA(DisplayName = "IntersectionMode")
};

UENUM(BlueprintType)
enum class EControllerIntersectionState : uint8
{
	CantIntersection UMETA(DisplayName = "CantIntersection"),
	HorizontalIntersection UMETA(DisplayName = "HorizontalIntersection"),
	VerticalIntersection UMETA(DisplayName = "VerticalIntersection")
};

UENUM(BlueprintType)
enum class TurretType : uint8
{
	EnergyTurret UMETA(DisplayName = "EnergyTurret"),
	BallisticTurret UMETA(DisplayName = "BallisticTurret"),
	MissileTurret UMETA(DisplayName = "MissileTurret")
};

USTRUCT(BlueprintType)
struct FMASAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag AttributeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	FMASAttribute()
		: AttributeTag(), Value(0.f)
	{
	}

	FMASAttribute(const FGameplayTag& InTag, float InValue)
		: AttributeTag(InTag), Value(InValue)
	{
	}
};

USTRUCT(BlueprintType)
struct FMASPawnAttribute
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute Hull = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Hull, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute Shield = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Shield, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute Energy = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Energy, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute Speed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Speed, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute MaxHull = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxHull, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute HullRepairRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_HullRepairRate, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute MaxShield = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxShield, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute ShieldRechargeRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_ShieldRechargeRate, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute MaxEnergy = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxEnergy, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute EnergyRechargeRate = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_EnergyRechargeRate, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute MaxSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_MaxSpeed, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute Acceleration = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_Acceleration, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute AlignSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_AlignSpeed, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute SensorRange = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_SensorRange, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute TargetLockSpeed = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_TargetLockSpeed, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMASAttribute AfterburnerPower = FMASAttribute(FMASGameplayTags::Get().Attributes_Ship_AfterburnerPower, 0.f);
};

/**
 * 
 */
class MASSTARGRAVE_API MASGlobalDefinitions
{
public:
	MASGlobalDefinitions();
	~MASGlobalDefinitions();
};
