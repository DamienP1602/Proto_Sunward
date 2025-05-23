//#include "Damien/CameraMap.h"
//#include <EnhancedInputComponent.h>
//#include <EnhancedInputSubsystems.h>
//#include <Kismet/KismetSystemLibrary.h>
//#include <Kismet/GameplayStatics.h>
//#include <Damien/Marker.h>
//#include "Damien/CameraOverlay.h"
//#include <Components/WidgetComponent.h>
//#include <Damien/MarkerWorld.h>
//#include "Damien/MarkerButton.h"
//
//// Sets default values
//ACameraMap::ACameraMap()
//{
//	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}
//
//// Called when the game starts or when spawned
//void ACameraMap::BeginPlay()
//{
//	Super::BeginPlay();
//	ULocalPlayer* _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
//	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
//
//	UEnhancedInputLocalPlayerSubsystem* _sub = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
//	if (!_sub) return;
//
//	_sub->AddMappingContext(mapping, 0);
//
//	SetActorRotation(FRotator(-40.0f, 0.0f, 0.0f));
//}
//
//FVector2D ACameraMap::GetMousePosition(APlayerController* _controller)
//{
//	float _mouseX;
//	float _mouseY;
//	_controller->GetMousePosition(_mouseX, _mouseY);
//
//	return FVector2D(_mouseX, _mouseY);
//}
//
//// Called every frame
//void ACameraMap::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//
//}
//
//// Called to bind functionality to input
//void ACameraMap::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	UEnhancedInputComponent* _inputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
//	if (!_inputCompo) return;
//
//	_inputCompo->BindAction(interact, ETriggerEvent::Started, this, &ACameraMap::Interaction);
//	_inputCompo->BindAction(returnInteract, ETriggerEvent::Started, this, &ACameraMap::Deselect);
//}
//
//void ACameraMap::Interaction()
//{
//	UKismetSystemLibrary::PrintString(this, "INTERACT");
//	if (!canClick) return;
//
//	FHitResult _result;
//	if (LaunchLineTrace(_result))
//	{
//		AMarker* _marker = Cast<AMarker>(_result.GetActor());
//		if (!_marker)
//		{
//			if (IsAllMarkedCreated())
//			{
//				AMarker* _lastMarker = allMarkerCreated[2];
//				if (!_lastMarker) return;
//
//				_lastMarker->OnDestroyMarker().Broadcast(_lastMarker);
//			}
//
//			AMarker* _newMarker = CreateMarker(_result.Location);
//			if (!_newMarker) return;
//
//			SetMarkerPosition(_newMarker);
//			UWidgetComponent* _widgetComp = _newMarker->GetWidget();
//			if (!_widgetComp) return;
//
//			UMarkerWorld* _markerWidget = Cast<UMarkerWorld>(_widgetComp->GetWidget());
//			if (!_markerWidget) return;
//
//			if (_newMarker->GetMarkerNum() > markerColors.Num()) return;
//
//			FLinearColor _color = markerColors[_newMarker->GetMarkerNum()];
//
//			_markerWidget->GetIcon()->SetColorAndOpacity(_color);
//		}
//		else
//		{
//			APlayerController* _controller = GetWorld()->GetFirstPlayerController();
//			overlay->CreateMarkerButton(GetMousePosition(_controller), _marker);
//			canClick = false;
//		}
//	}
//}
//
//void ACameraMap::Deselect()
//{
//	overlay->GetRemoveButton()->SetVisibility(ESlateVisibility::Hidden);
//	canClick = true;
//}
//
//bool ACameraMap::LaunchLineTrace(FHitResult& _result)
//{
//	APlayerController* _controller = GetWorld()->GetFirstPlayerController();
//
//	FVector2D _mousePos = GetMousePosition(_controller);
//
//	FVector _worldPosition;
//	FVector _worldDirection;
//	UGameplayStatics::DeprojectScreenToWorld(_controller, FVector2D(_mousePos.X, _mousePos.Y), _worldPosition, _worldDirection);
//
//	const FVector& _endDirection = (_worldDirection * 10000.0f) + _worldPosition;
//	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(),
//		_worldPosition,
//		_endDirection,
//		{ markerLayer,groundLayer },
//		true,
//		{ },
//		EDrawDebugTrace::ForDuration,
//		_result,
//		true);
//
//	return _hit;
//}
//
//AMarker* ACameraMap::CreateMarker(const FVector& _position)
//{
//	AMarker* _newMarker = GetWorld()->SpawnActor<AMarker>(markerSub, _position, FRotator::ZeroRotator);
//	if (!_newMarker) return nullptr;
//
//	_newMarker->OnDestroyMarker().AddDynamic(this, &ACameraMap::DeleteMarker);
//
//	return _newMarker;
//}
//
//bool ACameraMap::IsAllMarkedCreated()
//{
//	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
//	{
//		if (_pair.Value == nullptr) return false;
//	}
//	return true;
//}
//
//void ACameraMap::SetMarkerPosition(AMarker* _marker)
//{
//	int _index = 0;
//	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
//	{
//		if (_pair.Value == nullptr)
//		{
//			_marker->SetMarkerNum(_index);
//			//_pair.Value = _marker;
//			allMarkerCreated[_index] = _marker;
//			return;
//		}
//		_index++;
//	}
//}
//
//void ACameraMap::DeleteMarker(AMarker* _marker)
//{
//	int _indexMarker = _marker->GetMarkerNum();
//	allMarkerCreated[_indexMarker] = nullptr;
//
//	_marker->Destroy();
//	canClick = true;
//	const int _amount = GetAmountOfMarkerCreated();
//	const FString& _text = "Marker : " + FString::FromInt(_amount) + "/3";
//	overlay->SetText(_text);
//}
//
//int ACameraMap::GetAmountOfMarkerCreated()
//{
//	int _amount = 0;
//	for (TPair<int, TObjectPtr<AMarker>> _pair : allMarkerCreated)
//	{
//		if (_pair.Value != nullptr)
//			_amount++;
//	}
//	return _amount;
//}
//
