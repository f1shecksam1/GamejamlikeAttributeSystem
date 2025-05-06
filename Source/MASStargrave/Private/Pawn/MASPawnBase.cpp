// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/MASPawnBase.h"
#include "MyAbilitySystem/MASPawnAttributeSet.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ChildActorComponent.h"
#include "Component/MASMovementComponent.h"
#include "MASGameplayTags.h"

// Sets default values
AMASPawnBase::AMASPawnBase()
{
	PrimaryActorTick.bCanEverTick = false;

	ShipCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("ShipCollision"));
	RootComponent = ShipCollision;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->SetupAttachment(RootComponent);
	ShipMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	TurretActor1 = CreateDefaultSubobject<UChildActorComponent>(TEXT("TurretActor"));
	TurretActor1->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UMASMovementComponent>(TEXT("MovementComponent"));

	AttributeSet = CreateDefaultSubobject<UMASPawnAttributeSet>(TEXT("AttributeSet"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

}

void AMASPawnBase::BeginPlay()
{
	Super::BeginPlay();
}

void AMASPawnBase::InitAbilityActorInfo()
{
}

void AMASPawnBase::InitializeAttributes()
{
	if (PawnAttributeInfo)
	{
		UMASPawnAttributeSet* PawnAttributeSet = Cast<UMASPawnAttributeSet>(GetMASAttributeSet());
		PawnAttributeSet->OnAttributeChanged.AddDynamic(this, &AMASPawnBase::BindAttributeValue);
		PawnAttributeSet->InitializeAttributes(PawnAttributeInfo);
	}
}

void AMASPawnBase::BindAttributeValue(FGameplayTag AttributeTag, float Value)
{
	if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_Hull))
	{
		// Handle hull change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_Shield))
	{
		// Handle shield change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_Energy))
	{
		// Handle energy change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_MaxHull))
	{
		// Handle max hull change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_HullRepairRate))
	{
		// Handle hull repair rate change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_MaxShield))
	{
		// Handle max shield change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_ShieldRechargeRate))
	{
		// Handle shield recharge rate change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_MaxEnergy))
	{
		// Handle max energy change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_EnergyRechargeRate))
	{
		// Handle energy recharge rate change
	}
	else if (AttributeTag == FMASGameplayTags::Get().Attributes_Ship_Speed) 
	{
		MovementComponent->SetSpeed(Value);
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_MaxSpeed))
	{
		// Handle max speed change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_Acceleration))
	{
		MovementComponent->SetAcceleration(Value);
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_AlignSpeed))
	{
		MovementComponent->SetAlignSpeed(Value);
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_SensorRange))
	{
		// Handle sensor range change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_TargetLockSpeed))
	{
		// Handle target lock speed change
	}
	else if (AttributeTag.MatchesTagExact(FMASGameplayTags::Get().Attributes_Ship_AfterburnerPower))
	{
		// Handle afterburner power change
	}
}

