#include "World/GameMode/MainGameMode.h"

AMainGameMode::AMainGameMode()
{
    // Set default pawn class to our blueprinted character.
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/MainCharacter/Blueprints/MainCharacter_BP"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}