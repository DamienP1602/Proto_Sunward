#include "GPEs/RopeActor.h"
#include "CableComponent.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include <Kismet/GameplayStatics.h>


ARopeActor::ARopeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	isPlaced = false;
	isOverstretched = false;
	CableComponent->bEnableStiffness = true;

	ropePickupZone = CreateDefaultSubobject<USphereComponent>("RopePickupZone");
	ropePickupZone->SetupAttachment(RootComponent);
	ropePickupZone->SetSphereRadius(50.f);
	ropePickupZone->SetHiddenInGame(false);
	ropePickupZone->SetGenerateOverlapEvents(true);
}

void ARopeActor::UpdateMaterial(const bool _mat)
{
	UMaterialInterface* _newMat = _mat ? overstretchedMaterial : normalMaterial;
	if (_newMat)
	{
		CableComponent->SetMaterial(0, _newMat);
	}
}


void ARopeActor::BeginPlay()
{
	Super::BeginPlay();
	playerOwner = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	CableComponent->bEnableStiffness = true;
}

void ARopeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ARopeActor::GetRopeDistance()
{
	if (!CableComponent || !isPlaced)
		return 0.f;

	FVector _startLocation = CableComponent->GetComponentLocation();

	TArray<FVector> _particleLocations;
	CableComponent->GetCableParticleLocations(_particleLocations);

	if (_particleLocations.Num() > 0)
	{
		FVector _endLocation = _particleLocations.Last();
		//UKismetSystemLibrary::DrawDebugLine(GetWorld(), _startLocation, _endLocation, FLinearColor::Green, 60.f, 30.f);
		float _distance = FVector::Dist(_startLocation, _endLocation);
		// UKismetSystemLibrary::PrintString(GetWorld(), FString::Printf(TEXT("Distance: %.1f"), _distance));
		return _distance;
	}

	return 0.f;
}


