#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "MainCharacter.generated.h"

UCLASS()
class PROJECT_API AMainCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	// Default constructor.
	// Sets default values for this character's properties.
	AMainCharacter();

protected:
    // Called when the game starts or when spawned.
    virtual void BeginPlay() override;

public:
    // Called every frame.
    virtual void Tick(float DeltaTime) override;

// Camera ------------------------------------------------------------------------------------------

public:
    // Declare the arm holding the camera.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class USpringArmComponent *CameraBoom;

    // Declare the camera.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    class UCameraComponent *FollowCamera;
};
