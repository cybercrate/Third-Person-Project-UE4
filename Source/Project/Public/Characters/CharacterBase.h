#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(Abstract)
class PROJECT_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Default constructor.
	// Sets default values for this character's properties.
	ACharacterBase();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:
	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

// Properties --------------------------------------------------------------------------------------

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDead;

// Public Functions --------------------------------------------------------------------------------

public:
	UFUNCTION()
	bool IsAlive();

    // Movement ------------------------------------------------------------------------------------

public:
	// Movement forward, backward.
	void MoveForward(float Axis);

	// Movement left, right.
	void MoveRight(float Axis);

	void Jump();
	void StopJumping();

	void Sprint();
	void Walk();
};
