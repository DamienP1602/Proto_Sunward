// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectionnalRopeGPE.h"
#include <Components/BoxComponent.h>
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ADirectionnalRopeGPE::ADirectionnalRopeGPE()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectionnalRopeGPE::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectionnalRopeGPE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectionnalRopeGPE::SetBoxCollisionLockVector(UBoxComponent* _box, const FVector& _vectorToSet)
{
	FBodyInstance* _bodyInstance = _box->GetBodyInstance();
	_bodyInstance->SetDOFLock(EDOFMode::CustomPlane);
	_bodyInstance->CustomDOFPlaneNormal = _vectorToSet;
	//UKismetSystemLibrary::ResetEditorProperty(_box, "CustomDOFPlaneNormal", EPropertyAccessChangeNotifyMode::Always);
}

