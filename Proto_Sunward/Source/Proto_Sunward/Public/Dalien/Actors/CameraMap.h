// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <InputMappingContext.h>
#include "CameraMap.generated.h"

class AMarker;
class ACameraOverlay;

UCLASS()
class PROTO_SUNWARD_API ACameraMap : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputMappingContext> mapping;
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> interact;
	UPROPERTY(EditAnywhere) TEnumAsByte<EObjectTypeQuery> markerLayer;
	UPROPERTY(EditAnywhere) TMap<int, TObjectPtr<AMarker>> allMarkerCreated;
	UPROPERTY(EditAnywhere) TSubclassOf<AMarker> markerSub;
	UPROPERTY(EditAnywhere) TObjectPtr<ACameraOverlay> overlay;
	bool canClick = true;

public:
	// Sets default values for this pawn's properties
	ACameraMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION() void Interaction();
	bool LaunchLineTrace(FHitResult& _result);
	void CreateMarker();

	bool IsAllMarkedCreated();

	void SetMarkerPosition(AMarker* _marker);
	void DeleteMarker(AMarker* _marker);
	
	int GetAmountOfMarkerCreated();
};
