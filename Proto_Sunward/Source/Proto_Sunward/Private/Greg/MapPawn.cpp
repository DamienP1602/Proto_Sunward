// Fill out your copyright notice in the Description page of Project Settings.


#include "Greg/MapPawn.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Kismet/KismetMathLibrary.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
AMapPawn::AMapPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("movement");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	camera->SetupAttachment(RootComponent);
	AddOwnedComponent(movement);
}

// Called when the game starts or when spawned
void AMapPawn::BeginPlay()
{
	Super::BeginPlay();


	movement->MaxSpeed = moveSpeed;
	movement->Acceleration = moveSpeed;
	movement->Deceleration = moveSpeed * 10;
}

void AMapPawn::Move(const FInputActionValue& _value)
{
	if (hitLocation != FVector::ZeroVector)
		hitLocation = FVector::ZeroVector;
	const FRotator& _controlRotation = GetControlRotation();
	const FVector& _worldDirection = UKismetMathLibrary::GetRightVector(FRotator(0, _controlRotation.Yaw, _controlRotation.Roll));
	const FVector2D& _vector = _value.Get<FVector2D>();
	AddMovementInput(_worldDirection, _vector.X);
	const FVector& _direction = UKismetMathLibrary::GetForwardVector(FRotator(0, _controlRotation.Yaw, 0));
	AddMovementInput(_direction, _vector.Y);
	lastLocation = GetActorLocation();
}

void AMapPawn::Look(const FInputActionValue& _value)
{
	if (useController)
		Rotate(_value);
	else if (holdRightClick)
		Rotate(_value);
}

void AMapPawn::Rotate(const FInputActionValue& _value)
{
	const FVector2D _vector = _value.Get<FVector2D>();
	AddControllerYawInput(_vector.X * rotationSpeed);
	AddControllerPitchInput(_vector.Y * rotationSpeed);
}

void AMapPawn::RightClickPressed()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	holdRightClick = true;
	float _mousePosX = 0.0f;
	float _mousePosY = 0.0f;
	_controller->GetMousePosition(_mousePosX, _mousePosY);
	lastMousePos = FVector2D(_mousePosX, _mousePosY);
}

void AMapPawn::RightClickReleased()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	holdRightClick = false;
	_controller->SetMouseLocation(lastMousePos.X, lastMousePos.Y);
}

void AMapPawn::Zoom(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	const FVector& _start = GetActorLocation();
	const FVector& _end = _start + (GetActorForwardVector() * distanceBeforeZoomClamp);
	if (_axis > 0.0f)
	{
		FHitResult _result;
		if (GetWorld()->LineTraceSingleByChannel(_result, _start, _end, ECollisionChannel::ECC_Visibility)) return;
	}
	const float _zoomValue = zoomOffset * _axis;
	const FVector& _newLoc = _start + GetActorForwardVector() * _zoomValue;
	SetActorLocation(_newLoc);
}

void AMapPawn::SwitchToPlayer()
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
	_controller->Possess(player);
}

void AMapPawn::TeleportMouse()
{
	if (holdRightClick)
	{
		APlayerController* _controller = GetWorld()->GetFirstPlayerController();
		_controller->SetMouseLocation(0, 0);
	}
}

void AMapPawn::ClampPosition()
{
	if (FVector::Dist(map->GetActorLocation(), GetActorLocation()) > maxDistanceFromMap)
	{
		SetActorLocation(lastLocation);
	}
}

void AMapPawn::AdjustHeight()
{
	const FVector& _start = GetActorLocation();
	const FVector& _down = FVector::DownVector;
	const FVector& _end = (_down * maxDistanceWithFloor) + _start;
	DrawDebugLine(GetWorld(), _start, _end, FColor::Red);
	FHitResult _result;
	if (!GetWorld()->LineTraceSingleByChannel(_result, _start, _end, ECollisionChannel::ECC_Visibility)) return;

	UKismetSystemLibrary::PrintString(this, "Collide");
	const FVector& _location = FVector(_result.Location.X, _result.Location.Y, _result.Location.Z + maxDistanceWithFloor);
	SetActorLocation(_location);

}

// Called every frame
void AMapPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TeleportMouse();
	AdjustHeight();
	ClampPosition();
	lastLocation = GetActorLocation();
}

// Called to bind functionality to input
void AMapPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	TObjectPtr<ULocalPlayer> _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	if (!_localPlayer) return;
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _subsystem = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_subsystem) return;
	_subsystem->AddMappingContext(mapping, 0);
	TObjectPtr<UEnhancedInputComponent> _component = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (_component)
	{
		_component->ClearActionBindings();
		_component->BindAction(moveAction, ETriggerEvent::Triggered, this, &AMapPawn::Move);
		_component->BindAction(lookAction, ETriggerEvent::Triggered, this, &AMapPawn::Look);
		_component->BindAction(rightClickAction, ETriggerEvent::Started, this, &AMapPawn::RightClickPressed);
		_component->BindAction(rightClickAction, ETriggerEvent::Completed, this, &AMapPawn::RightClickReleased);
		_component->BindAction(zoomAction, ETriggerEvent::Triggered, this, &AMapPawn::Zoom);
		_component->BindAction(switchToPlayerAction, ETriggerEvent::Started, this, &AMapPawn::SwitchToPlayer);
	}
}

