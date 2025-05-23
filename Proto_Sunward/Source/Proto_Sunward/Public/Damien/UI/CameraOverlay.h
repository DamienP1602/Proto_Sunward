#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "CameraOverlay.generated.h"

class UMarkerButton;
class AMarker;

UCLASS()
class PROTO_SUNWARD_API UCameraOverlay : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (BindWidget)) TObjectPtr<UTextBlock> markerAmountText;
	UPROPERTY(EditAnywhere) TSubclassOf<UMarkerButton> buttonRef;
	UPROPERTY(EditAnywhere) TObjectPtr<UMarkerButton> removeButton;

public:
	FORCEINLINE TObjectPtr<UMarkerButton> GetRemoveButton() const { return removeButton; }

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	

public:
	void CreateMarkerButton(const FVector2D& _position, AMarker* _marker);
	void SetText(const FString& _text);
};
