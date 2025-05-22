// Fill out your copyright notice in the Description page of Project Settings.


#include "Dalien/Actors/CameraMap.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include <Damien/Actors/Marker.h>

// Sets default values
ACameraMap::ACameraMap()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraMap::BeginPlay()
{
	Super::BeginPlay();
	ULocalPlayer* _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	UEnhancedInputLocalPlayerSubsystem* _sub = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_sub) return;

	_sub->AddMappingContext(mapping, 0);
}

// Called every frame
void ACameraMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ACameraMap::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _inputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!_inputCompo) return;

	_inputCompo->BindAction(interact, ETriggerEvent::Started, this, &ACameraMap::Interaction);
}

void ACameraMap::Interaction()
{
	UKismetSystemLibrary::PrintString(this, "INTERACT");
	if (!canClick) return;

	FHitResult _result;
	if (LaunchLineTrace(_result))
	{
		AMarker* _marker = Cast<AMarker>(_result.GetActor());
		if (!_marker)
		{
			if (IsAllMarkedCreated())
			{
				CreateMarker();
			}
			else
			{

			}
		}
	}
}

bool ACameraMap::LaunchLineTrace(FHitResult& _result)
{
	APlayerController* _controller = GetWorld()->GetFirstPlayerController();

	float _mouseX;
	float _mouseY;
	_controller->GetMousePosition(_mouseX, _mouseY);

	FVector _worldPosition;
	FVector _worldDirection;
	UGameplayStatics::DeprojectScreenToWorld(_controller, FVector2D(_mouseX, _mouseY), _worldPosition, _worldDirection);

	const FVector& _endDirection = (_worldDirection * 10000.0f) + _worldPosition;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(),
		_worldPosition,
		_endDirection,
		{ markerLayer },
		true,
		{ },
		EDrawDebugTrace::ForDuration,
		_result,
		true);

	return _hit;
}

void ACameraMap::CreateMarker()
{
	AMarker* _newMarker = GetWorld()->SpawnActor<AMarker>(markerSub);
	if (_newMarker) return;
	SetMarkerPosition(_newMarker);

	_newMarker->OnDestroyMarker().AddDynamic(this, &ACameraMap::DeleteMarker);

}

bool ACameraMap::IsAllMarkedCreated()
{
	for (TPair<int,TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value == nullptr) return false;
	}
	return true;
}

void ACameraMap::SetMarkerPosition(AMarker* _marker)
{
	int _index = 0;
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value == nullptr)
		{
			_marker->SetMarkerNum(_index);
			_pair.Value = _marker;
			return;
		}
		_index++;
	}
}

void ACameraMap::DeleteMarker(AMarker* _marker)
{
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value == _marker)
		{
			_pair.Value = nullptr;
			return;
		}
	}

	_marker->Destroy();
	canClick = true;
	const int _amount = GetAmountOfMarkerCreated();
	const FString& _text = "Marker : " + FString::FromInt(_amount) + "/3";

}

int ACameraMap::GetAmountOfMarkerCreated()
{
	int _amount = 0;
	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
	{
		if (_pair.Value != nullptr)
			_amount++;
	}
	return _amount;
}

