// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <InputMappingContext.h>
#include "PlayerCharacter_Damien.generated.h"

UCLASS()
class PROTO_SUNWARD_API APlayerCharacter_Damien : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputMappingContext> mapping;
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> interact;
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> openMap;
	UPROPERTY(EditAnywhere, Category = "Inputs") TObjectPtr<UInputAction> move;

public:
	// Sets default values for this character's properties
	APlayerCharacter_Damien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION() void Move(const FInputActionValue& _value);
	UFUNCTION() void OpenMap();

};
