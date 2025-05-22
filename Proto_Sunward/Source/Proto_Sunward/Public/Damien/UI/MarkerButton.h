// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include "MarkerButton.generated.h"

class AMarker;

UCLASS()
class PROTO_SUNWARD_API UMarkerButton : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (BindWidget)) TObjectPtr<UButton> removeButton;
	UPROPERTY(EditAnywhere) TObjectPtr<AMarker> marker;

public:
	FORCEINLINE void SetMarker(AMarker* _marker) { marker = _marker; }
	FORCEINLINE TObjectPtr<UButton> GetRemoveButton() const { return removeButton; }

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void Init(const FVector2D& _position, AMarker* _marker);

	UFUNCTION() void DestroyMark();
};
