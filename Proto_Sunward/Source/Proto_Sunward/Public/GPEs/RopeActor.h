// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CableActor.h"
#include "RopeActor.generated.h"

class USphereComponent;
class UCableComponent;
UCLASS()
class PROTO_SUNWARD_API ARopeActor : public ACableActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Rope Visual")
	UMaterialInterface* normalMaterial;

	UPROPERTY(EditAnywhere, Category = "Rope Visual")
	UMaterialInterface* overstretchedMaterial;

	UPROPERTY(EditAnywhere, Category = "Rope Param")
	bool isOverstretched;

	UPROPERTY(EditAnywhere, Category = "Rope Param")
	TObjectPtr<ACharacter> playerOwner;

	UPROPERTY(EditAnywhere, Category = "Rope Param")
	bool isPlaced;


public:
	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	USphereComponent* ropePickupZone;
	FORCEINLINE void SetIsPlaced(const bool _isPlaced) { isPlaced = _isPlaced; }
	FORCEINLINE void SetIsOverstretched(const bool _isOverstretched) { isOverstretched = _isOverstretched; }
	FORCEINLINE bool GetIsPlaced() { return isPlaced; }
	ARopeActor();
	void UpdateMaterial(const bool _mat);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	float GetRopeDistance();
};
