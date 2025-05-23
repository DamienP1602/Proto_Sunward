#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Image.h>
#include "MarkerWorld.generated.h"

UCLASS()
class PROTO_SUNWARD_API UMarkerWorld : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (BindWidget)) TObjectPtr<UImage> icon;

public:
	FORCEINLINE UImage* GetIcon() const { return icon; }
};
