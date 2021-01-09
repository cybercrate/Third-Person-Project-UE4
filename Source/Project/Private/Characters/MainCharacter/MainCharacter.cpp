#include "Characters/MainCharacter/MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMainCharacter::AMainCharacter()
{
    // Sets default values.

    // Set this character to call Tick() every frame.
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create and configure the SpringArmComponent.
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true;

    // Create and configure the camera.
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    CameraBoom->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned.
void AMainCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame.
void AMainCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}