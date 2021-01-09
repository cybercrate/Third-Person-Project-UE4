#include "Characters/CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Default constructor.
ACharacterBase::ACharacterBase()
{
    // Sets default values.

    // Set this character to call Tick() every frame.
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    bIsDead = false;

    // Set default capsule size.
    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

    // Disabling the dependence of character rotation on camera rotation.
    bUseControllerRotationPitch = false; // by default false

    // Rotating the character with the camera.
    bUseControllerRotationYaw = false; // by default true
    bUseControllerRotationRoll = false; // by default false

    // Configure MovementComponent.
    GetCharacterMovement()->bOrientRotationToMovement = true;
    // Camera rotation speed.
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // by default (0, 360, 0)
    // Jump force.
    GetCharacterMovement()->JumpZVelocity = 380.0f; // by default 420
    GetCharacterMovement()->AirControl = 0.2f;
    GetCharacterMovement()->MaxWalkSpeed = 200.0f;
    // Maximum slope angle.
    GetCharacterMovement()->SetWalkableFloorAngle(60);
}

// Called when the game starts or when spawned.
void ACharacterBase::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame.
void ACharacterBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Input -------------------------------------------------------------------------------------------

// Called to bind functionality to input.
void ACharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // AXIS:

    // Bind camera rotation.
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

    // Bind movement.
    PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterBase::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterBase::MoveRight);

    // ACTION:

    // Bind jump, stop jumping.
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterBase::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterBase::StopJumping);

    // Bind sprint.
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACharacterBase::Sprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACharacterBase::Walk);
}

// Movement ----------------------------------------------------------------------------------------

// Movement forward, backward.
void ACharacterBase::MoveForward(float Axis)
{
    if ((Controller != nullptr) && (Axis != 0.0f) && IsAlive()) {
        // PlayerController->IsInputKeyDown(EKeys::LeftShift))

        // Get the angle of the direction of the camera along the axis Yaw.
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

        // Calculate the vector (direction) of movement and set the movement.
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Axis);
    }
}

// Movement left, right.
void ACharacterBase::MoveRight(float Axis)
{
    if ((Controller != nullptr) && (Axis != 0.0f) && IsAlive()) {
        // Get the angle of the direction of the camera along the axis Yaw.
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

        // Calculate the vector (direction) of movement and set the movement.
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Axis);
    }
}

void ACharacterBase::Jump()
{
    if ((Controller != nullptr) && IsAlive()) {
        ACharacter::Jump();
    }
}

void ACharacterBase::StopJumping()
{
    if ((Controller != nullptr) && IsAlive()) {
        ACharacter::StopJumping();
    }
}

// Called if SHIFT pressed.
void ACharacterBase::Sprint()
{
    if ((Controller != nullptr) && IsAlive()) {
        GetCharacterMovement()->MaxWalkSpeed = 420.0f;
    }
}

// Called if SHIFT released or not pressed.
void ACharacterBase::Walk()
{
    if ((Controller != nullptr) && IsAlive()) {
        GetCharacterMovement()->MaxWalkSpeed = 200.0f;
    }
}

// -------------------------------------------------------------------------------------------------

bool ACharacterBase::IsAlive()
{
	return bIsDead ? false : true;
}
