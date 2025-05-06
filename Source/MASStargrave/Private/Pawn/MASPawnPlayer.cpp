// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/MASPawnPlayer.h"
#include "Camera/CameraComponent.h"
#include "Component/MASMovementComponent.h"
#include "MyAbilitySystem/MASAttributeSet.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/MASPlayerController.h"
#include "Player/MASPlayerState.h"
#include "UI/HUD/MASHUD.h"

AMASPawnPlayer::AMASPawnPlayer()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void AMASPawnPlayer::BeginPlay()
{
    Super::BeginPlay();

    InitAbilityActorInfo();
}

void AMASPawnPlayer::InitAbilityActorInfo()
{
    AMASPlayerState* MASPlayerState = GetPlayerState<AMASPlayerState>();
    check(MASPlayerState);

    UMASAttributeSet* MASAttributeSet = Cast<UMASAttributeSet>(GetMASAttributeSet());
    check(MASAttributeSet);

    if (AMASPlayerController* MASPlayerController = Cast<AMASPlayerController>(GetController()))
    {
        if (AMASHUD* MASHUD = Cast<AMASHUD>(MASPlayerController->GetHUD()))
        {
            MASHUD->InitOverlay(MASPlayerController, MASPlayerState, MASAttributeSet);
        }
    }

    InitializeAttributes();
}

void AMASPawnPlayer::SetSpringArmLength(float CurrentTargetArmLength)
{
    SpringArmComponent->TargetArmLength = CurrentTargetArmLength;
}

float AMASPawnPlayer::GetSpringArmLength()
{
    return SpringArmComponent->TargetArmLength;
}

void AMASPawnPlayer::SetShipDestination(const FVector& Destination)
{
    MovementComponent->SetDestination(Destination);
}


