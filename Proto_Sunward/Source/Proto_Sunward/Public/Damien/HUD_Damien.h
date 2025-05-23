// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Damien.generated.h"

class UCameraOverlay;

UCLASS()
class PROTO_SUNWARD_API AHUD_Damien : public AHUD
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<UCameraOverlay> overlaySub;

public:
	virtual void BeginPlay() override;

	void InitHUD();
};
