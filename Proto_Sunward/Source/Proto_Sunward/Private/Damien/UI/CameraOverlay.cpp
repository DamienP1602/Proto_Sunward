#include "Damien/UI/CameraOverlay.h"
#include "Blueprint/WidgetTree.h"
#include "Damien/UI/MarkerButton.h"

void UCameraOverlay::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCameraOverlay::NativeDestruct()
{
	Super::NativeDestruct();
	if (removeButton)
		removeButton->RemoveFromParent();
}

void UCameraOverlay::CreateMarkerButton(const FVector2D& _position, AMarker* _marker)
{
	if (!removeButton)
	{
		removeButton = WidgetTree->ConstructWidget(buttonRef);
		//Add to Viewport
	}
	else
		removeButton->SetVisibility(ESlateVisibility::Visible);

	removeButton->SetFocus();
	removeButton->Init(_position, _marker);
}

void UCameraOverlay::SetText(const FString& _text)
{
	markerAmountText->SetText(FText::FromString(_text));
}
