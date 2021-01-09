#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "CharacterHUD.generated.h"

UCLASS()
class PROJECT_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACharacterHUD();
	
protected:
	virtual void DrawHUD() override;

	FCanvasIcon CenterDotIcon;
	
	void DrawCenterDot();
};
