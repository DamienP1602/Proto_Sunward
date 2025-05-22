#include "Damien/Actors/Marker.h"
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AMarker::AMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMarker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMarker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateToCamera();
}

void AMarker::RotateToCamera()
{
	APlayerCameraManager* _cameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(),0);
	if (!_cameraManager) return;

	const FVector& _cameraPos = _cameraManager->GetCameraLocation();
	const FRotator& _rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),_cameraPos);

	const FRotator& _newRotation = FRotator(0.0,0.0f, _rot.Yaw);
	SetActorRotation(_newRotation);
}

