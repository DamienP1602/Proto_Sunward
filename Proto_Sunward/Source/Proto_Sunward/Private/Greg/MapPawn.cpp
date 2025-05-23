// Fill out your copyright notice in the Description page of Project Settings.


#include "Greg/MapPawn.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Kismet/KismetMathLibrary.h"
#include <Kismet/KismetSystemLibrary.h>
#include "Damien/Marker.h"
#include <Damien/MarkerWorld.h>
#include "Damien/CameraOverlay.h"
#include "Damien/MarkerButton.h"
#include "Components/WidgetComponent.h"
#include <Kismet/GameplayStatics.h>

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

void AMapPawn::Interaction()
{
	if (!canClick) return;
	UKismetSystemLibrary::PrintString(this, "INTERACT");

	FHitResult _result;
	if (LaunchLineTrace(_result))
	{
		AMarker* _marker = Cast<AMarker>(_result.GetActor());
		if (!_marker)
		{
			if (IsAllMarkedCreated())
			{
				AMarker* _lastMarker = allMarkerCreated[2];
				if (!_lastMarker) return;

				_lastMarker->OnDestroyMarker().Broadcast(_lastMarker);
			}

			AMarker* _newMarker = CreateMarker(_result.Location);
			if (!_newMarker) return;

			SetMarkerPosition(_newMarker);
			UWidgetComponent* _widgetComp = _newMarker->GetWidget();
			if (!_widgetComp) return;

			UMarkerWorld* _markerWidget = Cast<UMarkerWorld>(_widgetComp->GetWidget());
			if (!_markerWidget) return;

			if (_newMarker->GetMarkerNum() > markerColors.Num()) return;

			FLinearColor _color = markerColors[_newMarker->GetMarkerNum()];

			_markerWidget->GetIcon()->SetColorAndOpacity(_color);
		}
		else
		{
			APlayerController* _controller = GetWorld()->GetFirstPlayerController();
			overlay->CreateMarkerButton(GetMousePosition(_controller), _marker);
			canClick = false;
		}
	}
}

void AMapPawn::Deselect()
{
	overlay->GetRemoveButton()->SetVisibility(ESlateVisibility::Hidden);
	canClick = true;
}

bool AMapPawn::LaunchLineTrace(FHitResult& _result)
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();

	FVector2D _mousePos = GetMousePosition(_controller);

	FVector _worldPosition;
	FVector _worldDirection;
	UGameplayStatics::DeprojectScreenToWorld(_controller, FVector2D(_mousePos.X, _mousePos.Y), _worldPosition, _worldDirection);

	const FVector& _endDirection = (_worldDirection * 10000.0f) + _worldPosition;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(),
		_worldPosition,
		_endDirection,
		{ markerLayer,groundLayer },
		true,
		{ },
		EDrawDebugTrace::ForDuration,
		_result,
		true);

	return _hit;
}

AMarker* AMapPawn::CreateMarker(const FVector& _position)
{
	AMarker* _newMarker = GetWorld()->SpawnActor<AMarker>(markerSub, _position, FRotator::ZeroRotator);
	if (!_newMarker) return nullptr;

	_newMarker->OnDestroyMarker().AddDynamic(this, &AMapPawn::DeleteMarker);

	return _newMarker;
}

bool AMapPawn::IsAllMarkedCreated()
{
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value == nullptr) return false;
	}
	return true;
}

void AMapPawn::SetMarkerPosition(AMarker* _marker)
{
	int _index = 0;
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value == nullptr)
		{
			_marker->SetMarkerNum(_index);
			//_pair.Value = _marker;
			allMarkerCreated[_index] = _marker;
			return;
		}
		_index++;
	}
}

void AMapPawn::DeleteMarker(AMarker* _marker)
{
	int _indexMarker = _marker->GetMarkerNum();
	allMarkerCreated[_indexMarker] = nullptr;

	_marker->Destroy();
	canClick = true;
	const int _amount = GetAmountOfMarkerCreated();
	const FString& _text = "Marker : " + FString::FromInt(_amount) + "/3";
	overlay->SetText(_text);
}

int AMapPawn::GetAmountOfMarkerCreated()
{
	int _amount = 0;
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value != nullptr)
			_amount++;
	}
	return _amount;
}

FVector2D AMapPawn::GetMousePosition(APlayerController* _controller)
{
	float _mouseX;
	float _mouseY;
	_controller->GetMousePosition(_mouseX, _mouseY);

	return FVector2D(_mouseX, _mouseY);
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

		_component->BindAction(interact, ETriggerEvent::Started, this, &AMapPawn::Interaction);
		_component->BindAction(deselect, ETriggerEvent::Started, this, &AMapPawn::Deselect);
	}
}

