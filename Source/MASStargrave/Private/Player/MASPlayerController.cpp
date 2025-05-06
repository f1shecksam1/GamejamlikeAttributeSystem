// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MASPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Input/MASEnhancedInputComponent.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Interaction/EnemyPawnInterface.h"
#include "Interaction/PlayerPawnInterface.h"
#include "MyAbilitySystem/MASAbilitySystemBlueprintLibrary.h"
#include "MASGameplayTags.h"

AMASPlayerController::AMASPlayerController()
{
    ControllerSelectionState = EControllerSelectionState::DefaultMode;
    ControllerIntersectionState = EControllerIntersectionState::HorizontalIntersection;
}

void AMASPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    CursorTrace();
}

void AMASPlayerController::CursorTrace()
{
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

    if (!CursorHit.bBlockingHit)
        return;

    LastActor = ThisActor;
    ThisActor = CursorHit.GetActor();

    if (LastActor != ThisActor)
    {
        if (LastActor)
            LastActor->UnhighLightActor();
        if (ThisActor)
            ThisActor->HighLightActor();
    }
}

void AMASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    check(MASContext);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (Subsystem)
        Subsystem->AddMappingContext(MASContext, 0);

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AMASPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UMASEnhancedInputComponent* MASEnhancedInputComponent = CastChecked<UMASEnhancedInputComponent>(InputComponent);

    MASEnhancedInputComponent->BindAction(MouseXYAction, ETriggerEvent::Triggered, this, &AMASPlayerController::MouseXY);
    MASEnhancedInputComponent->BindAction(MouseScrollAction, ETriggerEvent::Triggered, this, &AMASPlayerController::MouseScroll);

    MASEnhancedInputComponent->BindActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void AMASPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    if (InputTag == FMASGameplayTags::Get().InputTag_LMB)
    {
        LMBPressed();
    }
    else if (InputTag == FMASGameplayTags::Get().InputTag_RMB)
    {
        RMBPressed();
    }
}

void AMASPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (InputTag == FMASGameplayTags::Get().InputTag_LeftAlt)
    {
        LeftAltReleased();
    }
}

void AMASPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (InputTag == FMASGameplayTags::Get().InputTag_LeftAlt)
    {
        LeftAltHeld();
    }
}

void AMASPlayerController::LeftAltHeld()
{
    if (ControllerSelectionState == EControllerSelectionState::DefaultMode)
    {
        ControllerSelectionState = EControllerSelectionState::IntersectionMode;
    }
    else if (ControllerSelectionState == EControllerSelectionState::IntersectionMode)
    {
        if (ControllerIntersectionState == EControllerIntersectionState::CantIntersection)
        {
            return;
        }
        else if (ControllerIntersectionState == EControllerIntersectionState::HorizontalIntersection)
        {
            GetHorizontalIntersection();
        }
        else if (ControllerIntersectionState == EControllerIntersectionState::VerticalIntersection)
        {
            GetVerticalIntersection();
        }
    }
}

void AMASPlayerController::LeftAltReleased()
{
    if (ControllerIntersectionState == EControllerIntersectionState::CantIntersection || ControllerIntersectionState == EControllerIntersectionState::VerticalIntersection)
    {
        ControllerIntersectionState = EControllerIntersectionState::HorizontalIntersection;
    }
    if (ControllerSelectionState == EControllerSelectionState::IntersectionMode)
    {
        ControllerSelectionState = EControllerSelectionState::DefaultMode;
    }
}

void AMASPlayerController::LMBPressed()
{
    if (ControllerSelectionState == EControllerSelectionState::DefaultMode)
    {
        return;
    }
    else if (ControllerSelectionState == EControllerSelectionState::IntersectionMode)
    {
        if (ControllerIntersectionState == EControllerIntersectionState::CantIntersection)
        {
            return;
        }
        else if (ControllerIntersectionState == EControllerIntersectionState::HorizontalIntersection)
        {
            ControllerIntersectionState = EControllerIntersectionState::VerticalIntersection;
        }
        else if (ControllerIntersectionState == EControllerIntersectionState::VerticalIntersection)
        {
            if (PlayerShip == nullptr)
                PlayerShip = GetPawn();
            PlayerShip->SetShipDestination(FVector(HorizontalIntersection.X, HorizontalIntersection.Y, VerticalIntersection.Z));
            ControllerIntersectionState = EControllerIntersectionState::CantIntersection;
        }
    }
}

void AMASPlayerController::RMBPressed()
{
}

void AMASPlayerController::MouseXY(const FInputActionValue& Value)
{
    const FVector2D InputAxisValue = Value.Get<FVector2D>();
    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddControllerYawInput(InputAxisValue.X * CameraRotationSpeed * GetWorld()->GetDeltaSeconds());
        ControlledPawn->AddControllerPitchInput(-InputAxisValue.Y * CameraRotationSpeed * GetWorld()->GetDeltaSeconds());
    }
}

void AMASPlayerController::MouseScroll(const FInputActionValue& Value)
{
    const float InputAxisValue = Value.Get<float>();
    if (PlayerShip == nullptr)
        PlayerShip = GetPawn();
    if (PlayerShip)
    {
        float CameraZoomAddition = -InputAxisValue * CameraScrollSpeed * GetWorld()->GetDeltaSeconds();
        float CurrentTargetArmLength = FMath::Clamp(PlayerShip->GetSpringArmLength() + CameraZoomAddition, CameraZoomMin, CameraZoomMax);
        PlayerShip->SetSpringArmLength(CurrentTargetArmLength);
    }
}

void AMASPlayerController::GetHorizontalIntersection()
{
    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        FVector WorldLocation, WorldDirection;
        this->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
        float T = 0;
        bool bIntersects = UKismetMathLibrary::LinePlaneIntersection_OriginNormal(WorldLocation, WorldLocation + (WorldDirection * 50000), ControlledPawn->GetActorLocation(), FVector(0, 0, 1), T, HorizontalIntersection);

        if (bIntersects)
        {
            DrawDebugSphere(GetWorld(), HorizontalIntersection, 100, 12, FColor::Red, false, -1.0f);
            DrawDebugLine(GetWorld(), ControlledPawn->GetActorLocation(), HorizontalIntersection, FColor::Red, false, -1.0f);
        }
    }
}

void AMASPlayerController::GetVerticalIntersection()
{
    FVector WorldLocation, WorldDirection;
    this->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
    APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
    if (CameraManager)
    {
        FVector CameraNormalVector = CameraManager->GetActorForwardVector();
        FVector PlaneProjectionVector = FVector(CameraNormalVector.X, CameraNormalVector.Y, 0).GetSafeNormal();
        float T = 0;
        bool bIntersects = UKismetMathLibrary::LinePlaneIntersection_OriginNormal(WorldLocation, WorldLocation + (WorldDirection * 50000), HorizontalIntersection, PlaneProjectionVector, T, VerticalIntersection);

        if (bIntersects)
        {
            FVector DebugVector = FVector(HorizontalIntersection.X, HorizontalIntersection.Y, VerticalIntersection.Z);
            DrawDebugSphere(GetWorld(), DebugVector, 100, 12, FColor::Red, false, -1.0f);
            DrawDebugLine(GetWorld(), HorizontalIntersection, DebugVector, FColor::Red, false, -1.0f);
        }
    }
}





