// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <InputMappingContext.h>
#include "CameraMap.generated.h"

class AMarker;
class UCameraOverlay;

UCLASS()
class PROTO_SUNWARD_API ACameraMap : public APawn
{
	GENERATED_BODY()
//	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputMappingContext> mapping;
//	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> interact;
//	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> returnInteract;
//
//	UPROPERTY(EditAnywhere) TObjectPtr<UCameraOverlay> overlay;
//
//	UPROPERTY(EditAnywhere) TEnumAsByte<EObjectTypeQuery> markerLayer;
//	UPROPERTY(EditAnywhere) TEnumAsByte<EObjectTypeQuery> groundLayer;
//
//	UPROPERTY(EditAnywhere) TMap<int, TObjectPtr<AMarker>> allMarkerCreated;
//	UPROPERTY(EditAnywhere) TArray<FLinearColor> markerColors;
//
//	UPROPERTY(EditAnywhere, Category = "Subclass Of") TSubclassOf<AMarker> markerSub;
//	bool canClick = true;
//public:
//	FORCEINLINE void SetOverlay(UCameraOverlay* _overlay) { overlay = _overlay; }
//
//public:
//	// Sets default values for this pawn's properties
//	ACameraMap();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//	FVector2D GetMousePosition(APlayerController* _controller);
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//	UFUNCTION() void Interaction();
//	UFUNCTION() void Deselect();
//	bool LaunchLineTrace(FHitResult& _result);
//	AMarker* CreateMarker(const FVector& _position);
//	bool IsAllMarkedCreated();
//	void SetMarkerPosition(AMarker* _marker);
//	UFUNCTION() void DeleteMarker(AMarker* _marker);
//	int GetAmountOfMarkerCreated();
};
