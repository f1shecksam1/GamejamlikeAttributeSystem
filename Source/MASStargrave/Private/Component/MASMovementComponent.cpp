// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/MASMovementComponent.h"

UMASMovementComponent::UMASMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Destination = FVector::ZeroVector;
}

void UMASMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMASMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);
	AlignDestination(DeltaTime);
}

void UMASMovementComponent::Move(float DeltaTime)
{
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		return;
	}

	float EffectiveSpeed = (Speed / 100) * GetAlignmentPercentage();
	CurrentSpeed = FMath::FInterpTo(CurrentSpeed, EffectiveSpeed, DeltaTime, Acceleration);

	FVector ForwardVector = Owner->GetActorForwardVector();
	FVector Movement = ForwardVector * CurrentSpeed * DeltaTime;
	Owner->AddActorWorldOffset(Movement, true);
}

void UMASMovementComponent::AlignDestination(float DeltaTime)
{
	AActor* Owner = GetOwner();
	if (!Owner || Destination.IsNearlyZero())
		return;

	FVector Direction = (Destination - Owner->GetActorLocation()).GetSafeNormal();
	FRotator TargetRotation = Direction.Rotation();
	FRotator NewRotation = FMath::RInterpTo(
		Owner->GetActorRotation(),
		TargetRotation,
		DeltaTime,
		AlignSpeed);
	Owner->SetActorRotation(NewRotation);
}

float UMASMovementComponent::GetAlignmentPercentage() const
{
	AActor* Owner = GetOwner();
	if (!Owner || Destination.IsNearlyZero())
		return 0.0f;

	FVector CurrentDirection = Owner->GetActorForwardVector();
	FVector TargetDirection = (Destination - Owner->GetActorLocation()).GetSafeNormal();
	float DotProduct = FVector::DotProduct(CurrentDirection, TargetDirection);
	return (DotProduct + 1.0f) / 2.0f * 100.0f;
}

void UMASMovementComponent::SetSpeed(float NewSpeed)
{
	Speed = NewSpeed;
}

void UMASMovementComponent::SetAlignSpeed(float NewSpeed)
{
	AlignSpeed = NewSpeed;
}

void UMASMovementComponent::SetDestination(const FVector& NewDestination)
{
	Destination = NewDestination;
}

void UMASMovementComponent::SetAcceleration(float NewAcceleration)
{
	Acceleration = NewAcceleration;
}


