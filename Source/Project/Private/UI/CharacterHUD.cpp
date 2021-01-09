#include "UI/CharacterHUD.h" // T_CenterDot_M
#include "Characters/MainCharacter/MainCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"

ACharacterHUD::ACharacterHUD()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> HUDCenterDotObj(TEXT("/Game/UI/Textures/T_CenterDot_M"));
	CenterDotIcon = UCanvas::MakeIcon(HUDCenterDotObj.Object);
}

void ACharacterHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawCenterDot();
}

void ACharacterHUD::DrawCenterDot()
{
    float CenterX = Canvas->ClipX / 2;
    float CenterY = Canvas->ClipY / 2;
    float CenterDotScale = 0.07f;

    AMainCharacter *Pawn = Cast<AMainCharacter>(GetOwningPawn());
    if (Pawn && (Pawn->IsAlive())) {
        // Boost size when hovering over a usable object.
        CenterDotScale *= 1.5f;

        Canvas->SetDrawColor(255, 255, 255, 128);
        Canvas->DrawIcon(CenterDotIcon,
                         CenterX - CenterDotIcon.UL * CenterDotScale / 2.0f,
                         CenterY - CenterDotIcon.VL * CenterDotScale / 2.0f, CenterDotScale);
    }
}