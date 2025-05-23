#include "Components/PlayerComponents/RopeComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include <CableComponent.h>
#include "Components/BillboardComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include <GPEs/RopeActor.h>
#include "Components/SphereComponent.h"
#include "EngineUtils.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <PhysicsEngine/PhysicsConstraintActor.h>

URopeComponent::URopeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	isStartingRope = true;
	handSocketName = "hand_r";
	maxRopeLength = 1000;
	isBalancing = false;
	maxRaycastDistanceToPlaceRope = 100;
	tolerance = 100.f;
}

void URopeComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();

	GetWorld()->GetTimerManager().SetTimer(
		ropeCheckTimerHandle,
		this,
		&URopeComponent::CheckRopeStatus,
		0.5f,
		true
	);

}

void URopeComponent::RegisterRopeActor(ARopeActor* _rope)
{
	if (!_rope || !_rope->ropePickupZone) return;

	_rope->ropePickupZone->OnComponentBeginOverlap.AddDynamic(this, &URopeComponent::OnRopeZoneBeginOverlap);
	_rope->ropePickupZone->OnComponentEndOverlap.AddDynamic(this, &URopeComponent::OnRopeZoneEndOverlap);

}


void URopeComponent::OnRopeZoneBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UKismetSystemLibrary::PrintString(GetWorld(), "Work", true, true, FLinearColor::Green, 5.0f);

	if (OtherActor == GetOwner())
	{
		ropeToPickup = Cast<ARopeActor>(OverlappedComponent->GetOwner());
	}
}

void URopeComponent::OnRopeZoneEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == GetOwner())
	{
		//ropeToPickup = nullptr;
	}
}


void URopeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	PullPlayerTowardsRope(DeltaTime);

	FTimerHandle placementCheckTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		placementCheckTimerHandle,
		this,
		&URopeComponent::CheckPlacementLoop,
		0.5f,
		true
	);

	//FHitResult _outHitResult;
	//PerformForwardTrace(_outHitResult);
	//canBePlaced = CanBePlaced(_outHitResult.ImpactPoint);
}

void URopeComponent::CheckPlacementLoop()
{
	FHitResult _outHitResult;
	PerformForwardTrace(_outHitResult);
	canBePlaced = CanBePlaced(_outHitResult.ImpactPoint);
}

void URopeComponent::PullPlayerTowardsRope(float DeltaTime)
{
	if (!currentRope) return;
	if (!currentRope->CableComponent->bAttachEnd) return;
	if (currentRope->GetIsPlaced()) return;
	// get char
	ACharacter* _character = Cast<ACharacter>(GetOwner());
	if (!_character || !currentRope) return;

	FVector _ropeLocation = currentRope->GetActorLocation();
	FVector _playerLocation = _character->GetActorLocation();
	float _distance = FVector::Dist(_playerLocation, _ropeLocation) + GetCurrentRopeLenght();

	if (_distance <= maxRopeLength) return;

	float _excessLength = _distance - maxRopeLength;

	// compute length
	FVector _direction = (_ropeLocation - _playerLocation).GetSafeNormal();

	// test
	const float _springStiffness = 9000.f;
	FVector _springForce = _direction * (_excessLength * _springStiffness);

	_character->GetCharacterMovement()->AddForce(_springForce);
}

void URopeComponent::CheckRopeStatus()
{
	if (!currentRope || isStartingRope) return;
	const float _distance = FVector::Dist(currentRope->GetActorLocation(), GetOwner()->GetActorLocation());
	const bool _check = (_distance + GetCurrentRopeLenght()) > maxRopeLength;
	currentRope->UpdateMaterial(_check);
}

void URopeComponent::SetupInputComponent()
{
	if (APlayerController* _playerController = GetWorld()->GetFirstPlayerController())
	{
		if (_playerController->InputComponent)
		{
			_playerController->InputComponent->BindKey(EKeys::A, IE_Pressed, this, &URopeComponent::OnAPressed);
			_playerController->InputComponent->BindKey(EKeys::Gamepad_FaceButton_Top, IE_Pressed, this, &URopeComponent::OnAPressed);
			_playerController->InputComponent->BindKey(EKeys::E, IE_Pressed, this, &URopeComponent::OnEPressed);
			_playerController->InputComponent->BindKey(EKeys::Gamepad_FaceButton_Left, IE_Pressed, this, &URopeComponent::OnEPressed);
		}
	}
}

void URopeComponent::OnEPressed()
{
	DetachRope(currentRope);
}

void URopeComponent::DetachRope(TObjectPtr<ARopeActor> _rope)
{
	if (!_rope) return;
	_rope->CableComponent->bAttachEnd = false;
	_rope->SetIsPlaced(true);
	ropeNumber -= 1;

}
void URopeComponent::SetCurrentRope(ARopeActor* _currentRope)
{
	currentRope = _currentRope;
}

void URopeComponent::OnAPressed()
{
	if (ropeToPickup)
	{
		currentRope = ropeToPickup;
		AttachCableToHand(currentRope->CableComponent);
		ropeToPickup = nullptr;
		isStartingRope = false;
		UKismetSystemLibrary::PrintString(GetWorld(), "Corde récupérée !");
		return;
	}

	UseRope();
}

void URopeComponent::UseRope()
{
	if (ropeNumber == 0) return;

	FHitResult _hitResult;
	if (!PerformForwardTrace(_hitResult)) return;

	if (isStartingRope)
	{
		PlaceRope(_hitResult);
		return;
	}
	else
	{
		FVector _ropeActorLoc = currentRope->GetActorLocation();
		FVector _impactPoint = _hitResult.ImpactPoint;
		const float _combinedLength = GetCurrentRopeLenght() + FVector::Dist(_impactPoint, _ropeActorLoc);
		// UKismetSystemLibrary::DrawDebugLine(GetWorld(), _impactPoint, _ropeActorLoc, FLinearColor::Green, 60.f, 10.f);

		if (FMath::IsNearlyEqual(_combinedLength, maxRopeLength, tolerance))
		{
			AttachRopeToBillboard(_hitResult);
			return;
		}
		else if (CanBePlaced(_hitResult.ImpactPoint))
			PlaceHook(_hitResult);
	}


}

void URopeComponent::AttachRopeToBillboard(FHitResult _hitResult)
{
	if (!currentRope) return;

	// Create the billboard
	UBillboardComponent* _billboard = NewObject<UBillboardComponent>(GetOwner());
	if (!_billboard) return;

	_billboard->SetWorldLocation(_hitResult.ImpactPoint);
	_billboard->SetHiddenInGame(false);

	lastRopePoint = _billboard;

	// Attach rope to billboard
	if (UCableComponent* _cable = currentRope->GetComponentByClass<UCableComponent>())
	{
		_cable->SetAttachEndToComponent(lastRopePoint);
		isStartingRope = true;
		currentRopes.Empty();
		cablePlaced = 0;
		ropeNumber -= 1;
	}
	currentRope->SetIsPlaced(true);
	// UKismetSystemLibrary::PrintString(GetWorld(), "Work", true, true, FLinearColor::Green, 5.0f);
}

void URopeComponent::PlaceRope(FHitResult _hitResult)
{
	if (!ropeToSpawn) return;


	currentRope = CreateRope(_hitResult.ImpactPoint);
	if (!currentRope) return;
	currentRope->UpdateMaterial(CanBePlaced(_hitResult.ImpactPoint));

	if (UCableComponent* _cable = currentRope->GetComponentByClass<UCableComponent>())
	{
		AttachCableToHand(_cable);
		isStartingRope = false;
	}
	currentRopes.Add(currentRope);

	UKismetSystemLibrary::DrawDebugSphere(
		this,
		_hitResult.ImpactPoint,
		100.f,
		12,
		FLinearColor(1.f, 0.27f, 0.5f, 1.f),
		30.f,
		0.f
	);
}

void URopeComponent::PlaceHook(FHitResult _hitResult)
{
	TObjectPtr<ARopeActor> _tempRope = currentRope;
	if (!_tempRope) return;

	currentRope = CreateRope(_hitResult.ImpactPoint);
	if (!currentRope) return;

	if (UCableComponent* _cable = _tempRope->GetComponentByClass<UCableComponent>())
	{
		_cable->SetAttachEndToComponent(currentRope->GetRootComponent());
		currentRopes.Add(currentRope);
		_tempRope->SetIsPlaced(true);
		cablePlaced += 1;
	}

	if (UCableComponent* _cable = currentRope->GetComponentByClass<UCableComponent>())
	{
		AttachCableToHand(_cable);
	}
}

TObjectPtr<ARopeActor> URopeComponent::CreateRope(FVector _location)
{
	FTransform _spawnTransform;
	_spawnTransform.SetLocation(_location);
	currentRope = GetWorld()->SpawnActor<ARopeActor>(ropeToSpawn, _spawnTransform);
	//RegisterRopeActor(currentRope);
	return currentRope;
}

bool URopeComponent::PerformForwardTrace(FHitResult& OutHitResult)
{
	FVector _start = GetOwner()->GetActorLocation();
	FVector _end = _start + (GetOwner()->GetActorForwardVector() * maxRaycastDistanceToPlaceRope);
	return UKismetSystemLibrary::LineTraceSingleForObjects(
		this,
		_start,
		_end,
		climbLayer,
		false,
		TArray<AActor*>(),
		EDrawDebugTrace::ForOneFrame,
		OutHitResult,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		0.1f
	);
}

USkeletalMeshComponent* URopeComponent::GetCharacterMesh() const
{
	if (ACharacter* _characterOwner = Cast<ACharacter>(GetOwner()))
	{
		return _characterOwner->GetMesh();
	}
	return nullptr;
}

void URopeComponent::AttachCableToHand(UCableComponent* _cable)
{
	if (!_cable) return;

	if (USkeletalMeshComponent* _mesh = GetCharacterMesh())
	{
		_cable->SetAttachEndToComponent(_mesh, handSocketName);
	}
}

bool URopeComponent::CanBePlaced(const FVector& _distanceTo)
{
	if (!currentRope) return false;
	float _distance = FVector::Dist(currentRope->GetActorLocation(), _distanceTo) + GetCurrentRopeLenght();
	bool _result = _distance <= maxRopeLength;

	FString _strBool = _result ? "true" : "false";
	UKismetSystemLibrary::PrintString(GetWorld(), _strBool, true, true, FLinearColor::Green, 5.0f);
	UKismetSystemLibrary::PrintString(GetWorld(), "distance" + FString::SanitizeFloat(_distance), true, true, FLinearColor::Green, 5.0f);

	UKismetSystemLibrary::PrintString(GetWorld(), "Max distance" + FString::SanitizeFloat(maxRopeLength), true, true, FLinearColor::Green, 5.0f);
	currentRope->UpdateMaterial(!_result);
	return _result;
}

float URopeComponent::GetCurrentRopeLenght()
{
	float _result = 0;
	for (int _i = 0; _i < currentRopes.Num(); _i++)
	{
		_result += currentRopes[_i]->GetRopeDistance();
	}
	UKismetSystemLibrary::PrintString(GetWorld(), "result : " + FString::SanitizeFloat(_result), true, true, FLinearColor::Blue, 5.0f);
	UKismetSystemLibrary::PrintString(GetWorld(), "size of currentropes : " + FString::SanitizeFloat(currentRopes.Num()), true, true, FLinearColor::Blue, 5.0f);
	return _result;
}

void URopeComponent::EnterBalanceMode(FVector CableForward, FVector CableLocation)
{
	isBalancing = true;
	balanceDirection = CableForward;
	targetPosition = CableLocation;
}
