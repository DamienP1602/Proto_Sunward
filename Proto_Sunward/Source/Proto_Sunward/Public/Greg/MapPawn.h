// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <InputMappingContext.h>
#include <GameFramework/FloatingPawnMovement.h>
#include <Camera/CameraComponent.h>
#include "MapPawn.generated.h"

UCLASS()
class PROTO_SUNWARD_API AMapPawn : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<APawn> player = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> map = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UFloatingPawnMovement> movement = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> camera = nullptr;

	UPROPERTY(EditAnywhere) float moveSpeed = 1000.0f;
	UPROPERTY(EditAnywhere) float rotationSpeed = 1000.0f;
	UPROPERTY(EditAnywhere) float distanceBeforeZoomClamp = 1000.0f;
	UPROPERTY(EditAnywhere) float zoomOffset = 1000.0f;
	UPROPERTY(EditAnywhere) float maxDistanceFromMap = 1000.0f;
	UPROPERTY(EditAnywhere) float maxDistanceWithFloor = 1000.0f;

	UPROPERTY(VisibleAnywhere) FVector hitLocation = FVector::ZeroVector;
	UPROPERTY(VisibleAnywhere) FVector lastLocation = FVector::ZeroVector;
	UPROPERTY(VisibleAnywhere) FVector2D lastMousePos = FVector2D::ZeroVector;
	UPROPERTY(VisibleAnywhere) bool useController = false;
	UPROPERTY(VisibleAnywhere) bool holdRightClick = false;


	UPROPERTY(EditAnywhere) TObjectPtr<UInputMappingContext> mapping = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> moveAction = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> switchToPlayerAction = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> lookAction = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> rightClickAction = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> zoomAction = nullptr;


	UFUNCTION(BlueprintCallable) FORCEINLINE void SetUseController(bool _useController) { useController = _useController; }

public:
	// Sets default values for this pawn's properties
	AMapPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& _value);
	void Look(const FInputActionValue& _value);
	void Rotate(const FInputActionValue& _value);
	void RightClickPressed();
	void RightClickReleased();
	void Zoom(const FInputActionValue& _value);
	void SwitchToPlayer();
	void TeleportMouse();
	void ClampPosition();
	void AdjustHeight();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
