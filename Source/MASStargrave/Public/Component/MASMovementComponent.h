// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MASMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MASSTARGRAVE_API UMASMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMASMovementComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetSpeed(float NewSpeed);
	void SetAlignSpeed(float NewSpeed);
	void SetDestination(const FVector& NewDestination);
	void SetAcceleration(float NewAcceleration);
	float GetAlignmentPercentage() const;

protected:
	virtual void BeginPlay() override;

private:
	void Move(float DeltaTime);
	void AlignDestination(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float CurrentSpeed;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	FVector Destination;

	UPROPERTY(EditAnywhere)
	float Acceleration = 1.0f;

	UPROPERTY(EditAnywhere)
	float AlignSpeed = 1.0f;

		
};
