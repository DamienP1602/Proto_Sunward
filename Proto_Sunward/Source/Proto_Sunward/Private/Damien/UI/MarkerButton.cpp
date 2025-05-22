#include "Damien/UI/MarkerButton.h"
#include "Damien/Actors/Marker.h"

void UMarkerButton::NativeConstruct()
{
	Super::NativeConstruct();
	removeButton->OnClicked.AddDynamic(this,&UMarkerButton::DestroyMark);
}

void UMarkerButton::NativeDestruct()
{
	Super::NativeDestruct();

}

void UMarkerButton::Init(const FVector2D& _position, AMarker* _marker)
{
	SetMarker(_marker);

	SetPositionInViewport(_position + FVector2D(0.0f, 25.0f));
	SetDesiredSizeInViewport(FVector2D(75.0f, 25.0f));
	SetAlignmentInViewport(FVector2D(0.5f, 0.5f));
}

void UMarkerButton::DestroyMark()
{
	marker->OnDestroyMarker().Broadcast();
}
