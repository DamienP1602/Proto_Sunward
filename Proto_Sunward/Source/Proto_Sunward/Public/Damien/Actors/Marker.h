// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Marker.generated.h"

class UWidgetComponent;

UCLASS()
class PROTO_SUNWARD_API AMarker : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestroyMarker, AMarker*, _marker);
	UPROPERTY() FOnDestroyMarker onDestroyMarker;
	UPROPERTY(EditAnywhere) TObjectPtr<UWidgetComponent> markerWidget;
	int markerNum;
	
public:
	FORCEINLINE UWidgetComponent* GetWidget() const { return markerWidget; }
	FORCEINLINE void SetMarkerNum(int _value) { markerNum = _value; }
	FORCEINLINE int GetMarkerNum() const { return markerNum; }
	FORCEINLINE FOnDestroyMarker& OnDestroyMarker() { return onDestroyMarker; }

public:
	// Sets default values for this actor's properties
	AMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RotateToCamera();

};
