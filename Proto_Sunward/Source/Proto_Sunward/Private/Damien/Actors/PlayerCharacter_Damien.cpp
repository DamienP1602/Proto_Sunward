// Fill out your copyright notice in the Description page of Project Settings.


#include "Damien/Actors/PlayerCharacter_Damien.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include <Kismet/KismetSystemLibrary.h>

APlayerCharacter_Damien::APlayerCharacter_Damien()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerCharacter_Damien::BeginPlay()
{
	Super::BeginPlay();
	ULocalPlayer* _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* _sub = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_sub) return;

	_sub->AddMappingContext(mapping, 0);
}

void APlayerCharacter_Damien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter_Damien::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _inputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!_inputCompo) return;

	_inputCompo->BindAction(move,ETriggerEvent::Triggered, this, &APlayerCharacter_Damien::Move);
	_inputCompo->BindAction(openMap,ETriggerEvent::Triggered, this, &APlayerCharacter_Damien::OpenMap);
}


void APlayerCharacter_Damien::Move(const FInputActionValue& _value)
{
	const FVector2D& _movementValue = _value.Get<FVector2D>();

	const FVector& _forwardMovement = _movementValue.Y * GetWorld()->DeltaTimeSeconds * 500.0f * GetActorForwardVector();
	const FVector& _rightMovement = _movementValue.X * GetWorld()->DeltaTimeSeconds * 500.0f * GetActorRightVector();

	SetActorLocation(GetActorLocation() + _forwardMovement + _rightMovement);
}

void APlayerCharacter_Damien::OpenMap()
{

}

