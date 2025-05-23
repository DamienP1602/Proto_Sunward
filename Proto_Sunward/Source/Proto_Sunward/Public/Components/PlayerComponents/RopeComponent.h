// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CableActor.h"
#include "RopeComponent.generated.h"

class UBillboardComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTO_SUNWARD_API URopeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	unsigned int ropeNumber = 3;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	unsigned int cablePlaced = 0;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	TSubclassOf<ARopeActor> ropeToSpawn;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	TObjectPtr<ARopeActor> currentRope;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	bool isStartingRope;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	TObjectPtr<UBillboardComponent> lastRopePoint;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	FName handSocketName;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	TArray<TObjectPtr<ARopeActor>> currentRopes;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	float maxRopeLength;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	float maxRaycastDistanceToPlaceRope;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	TArray<TEnumAsByte<EObjectTypeQuery>> climbLayer;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	float tolerance;

	UPROPERTY(EditAnywhere, Category = "Rope Balance")
	bool isBalancing;

	UPROPERTY(EditAnywhere, Category = "Rope Balance")
	FVector balanceDirection;

	UPROPERTY(EditAnywhere, Category = "Rope Balance")
	FVector targetPosition;

	UPROPERTY()
	ARopeActor* ropeToPickup = nullptr;

	UPROPERTY(EditAnywhere, Category = "Rope Climb")
	bool canBePlaced;

	FTimerHandle ropeCheckTimerHandle;
public:
	UFUNCTION(BlueprintCallable) bool GetCanBePlaced() { return canBePlaced; }
	UFUNCTION(BlueprintCallable) void SetCurrentRope(ARopeActor* _currentRope);
	URopeComponent();
	virtual void BeginPlay() override;
	void RegisterRopeActor(ARopeActor* Rope);
	void OnRopeZoneBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnRopeZoneEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void CheckPlacementLoop();
	void PullPlayerTowardsRope(float DeltaTime);
	void EnterBalanceMode(FVector _cableForward, FVector _cableLocation);

private:
	void OnAPressed();
	void CheckRopeStatus();
	void UseRope();
	void AttachRopeToBillboard(FHitResult _hitResult);
	void PlaceRope(FHitResult _hitResult);
	void PlaceHook(FHitResult _hitResult);
	TObjectPtr<ARopeActor> CreateRope(FVector _location);
	bool PerformForwardTrace(FHitResult& OutHitResult);
	USkeletalMeshComponent* GetCharacterMesh() const;
	void AttachCableToHand(UCableComponent* _cable);
	bool CanBePlaced(const FVector& _distanceTo);
	float GetCurrentRopeLenght();
	virtual void SetupInputComponent();


	void OnEPressed();
	void DetachRope(TObjectPtr<ARopeActor> _cable);
};
