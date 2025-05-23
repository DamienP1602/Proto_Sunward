#include "Damien/HUD_Damien.h"
#include "Damien/CameraOverlay.h"
#include <Greg/MapPawn.h>
#include <Damien/CameraMap.h>

void AHUD_Damien::BeginPlay()
{
	Super::BeginPlay();
	InitHUD();
}

void AHUD_Damien::InitHUD()
{
	UCameraOverlay* _overlay = CreateWidget<UCameraOverlay>(GetWorld(), overlaySub);
	if (!_overlay) return;

	_overlay->AddToViewport();
	AMapPawn* _player = Cast<AMapPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (_player)
		_player->SetOverlay(_overlay);

	ACameraMap* _map = Cast<ACameraMap>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (_map)
		_map->SetOverlay(_overlay);

}
