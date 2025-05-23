// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectionnalRopeGPE.generated.h"

class UBoxComponent;

UCLASS()
class ADirectionnalRopeGPE : public AActor // WARNING, THIS CLASS AT THE MOMENT IS MADE TO DO SOMETHING BLUEPRINT CAN'T, THE TRUE CODE IS MADE IN BLUEPRINT
{
	GENERATED_BODY()
public:	
	ADirectionnalRopeGPE();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable) void SetBoxCollisionLockVector(UBoxComponent* _box, const FVector& _vectorToSet);
};
