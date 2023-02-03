// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CineCameraComponent.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType)
enum EAxisOrientation
{
	LONGITUDINAL				UMETA(DisplayName = "Longitudinal"),
	LATERAL						UMETA(DisplayName = "Lateral"),
};

UCLASS()
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	/** The Camera Controller responsible for controlling the camera.*/
	UPROPERTY(BlueprintGetter = GetCameraController, EditAnywhere, Category = Components, Meta = (DisplayName = "Camera Controller"))
	class UPlayerCharacterCameraController* CameraController {nullptr};

	/** The Audio Controller responsible for handling player audio. */
	UPROPERTY(BlueprintGetter = GetAudioController, EditAnywhere, Category = Components, Meta = (DisplayName = "Audio Controller"))
	class UPlayerCharacterAudioController* AudioController {nullptr};

	/** The VFX Controller responsible for handling player VFX. */
	UPROPERTY(BlueprintGetter = GetVFXController, EditAnywhere, Category = Components, Meta = (DisplayName = "VFX Controller"))
	class UPlayerCharacterVFXController* VFXController {nullptr};

	/** The Movement Component responsible for handling player audio. */
	UPROPERTY(BlueprintGetter = GetPlayerCharacterMovement, Category = Components, Meta = (DisplayName = "Player Character Movement"))
	class UPlayerCharacterMovementComponent* PlayerCharacterMovement {nullptr};

	/** The Camera for the player.*/
	UPROPERTY(BlueprintGetter = GetCamera, EditAnywhere, Category = Components, Meta = (DisplayName = "Camera"))
	class UCineCameraComponent* Camera {nullptr};

	/** The camera arm for the player. */
	UPROPERTY(BlueprintGetter = GetCameraArm, EditAnywhere, Category = Components, Meta = (DisplayName = "Camera Arm"))
	class USpringArmComponent* CameraArm {nullptr};
	
public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called after construction, but before Beginplay.
	virtual void PostInitProperties() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns the player Camera Controller. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Camera Controller"))
	FORCEINLINE UPlayerCharacterCameraController* GetCameraController() const {return CameraController; }
	
	/** Returns the player Audio Controller. */
    UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Audio Controller"))
    FORCEINLINE UPlayerCharacterAudioController* GetAudioController() const {return AudioController; }

	/** Returns the player VFX Controller. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "VFX Controller"))
	FORCEINLINE UPlayerCharacterVFXController* GetVFXController() const {return VFXController; }

	/** Returns the player CharacterMovementComponent. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Player Character Movement Component"))
	FORCEINLINE UPlayerCharacterMovementComponent* GetPlayerCharacterMovement() const {return PlayerCharacterMovement; }

	/** Returns the Camera. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Camera"))
	FORCEINLINE UCineCameraComponent* GetCamera() const {return Camera; }

	/** Returns the Camera Arm. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Camera Arm."))
	FORCEINLINE USpringArmComponent* GetCameraArm() const {return CameraArm; }

	/** Converts the camera rotation to an axis input. */
	UFUNCTION()
	void RotateToMouseCursor();

#if WITH_EDITOR
	/** Checks whether an object is a blueprint derived class or not. */
	static bool IsBlueprintClass(const UObject* Object)
	{return static_cast<bool>(Object->GetClass()->ClassFlags & CLASS_CompiledFromBlueprint);}
#endif

};
