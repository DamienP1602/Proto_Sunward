#include "Damien/HUD_Damien.h"
#include "Damien/CameraOverlay.h"
#include "Damien/CameraMap.h"

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
	ACameraMap* _player = Cast<ACameraMap>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!_player) return;

	_player->SetOverlay(_overlay);
}
