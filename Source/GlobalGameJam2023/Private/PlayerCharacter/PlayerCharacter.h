// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CineCameraComponent.h"
#include "PlayerCharacterConfiguration.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType)
enum EAxisOrientation
{
	LONGITUDINAL				UMETA(DisplayName = "Longitudinal"),
	LATERAL						UMETA(DisplayName = "Lateral"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStunned);

UCLASS()
class APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** The event delegate for when the player is stunned. */
	FOnStunned OnStunnedDelegate;
	
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

	/** The character configuration. */
	UPROPERTY(BlueprintGetter = GetConfiguration, EditAnywhere, Category = Configuration, Meta = (DisplayName = "Player Configuration"))
	FPlayerCharacterConfiguration CharacterConfiguration {FPlayerCharacterConfiguration()};

	/** When true, the player is currently stunned. */
	UPROPERTY(BlueprintGetter = GetIsStunned, Category = Default, Meta = (DisplayName = "Is Stunned"))
	bool IsStunned {false};

	/** The timer handle for the stun effect. */
	UPROPERTY()
	FTimerHandle StunTimerHandle;
	
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

	/** Returns the Player Character Configuration of the player. */
	UFUNCTION(BlueprintGetter, Category = Components, Meta = (DisplayName = "Character Configuration"))
	FORCEINLINE FPlayerCharacterConfiguration GetConfiguration() const {return CharacterConfiguration; }

	/** Returns whether the player is currently stunned. */
	UFUNCTION(BlueprintGetter, Category = Default, Meta = (DisplayName = "Is Stunned"))
	FORCEINLINE bool GetIsStunned() const {return IsStunned; }

	/** Returns whether the player can currently sprint. */
	UFUNCTION(BlueprintGetter, Category = Default, meta = (DisplayName = "Can Sprint"))
	FORCEINLINE bool CanSprint() const {return !IsStunned; }
	
	/** Stuns the player.
	 *	@Duration Defines how long the player should remain stunned.
	 *	@Intensity Defines how much the player should be stunned. Value equals percentage of movement speed reduction: a value of 100 or above will completely lock the player.
	 */
	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Stun Player"))
	void Stun(const float Duration, const int Intensity);

	UFUNCTION(BlueprintPure, Category = Default, Meta = (DisplayName = "Get XY Velocity"))
	FVector2D GetCharacterXYVelocity();

private:
#if WITH_EDITOR
	/** Checks whether an object is a blueprint derived class or not. */
	static bool IsBlueprintClass(const UObject* Object)
	{return static_cast<bool>(Object->GetClass()->ClassFlags & CLASS_CompiledFromBlueprint);}
#endif

	UFUNCTION()
	void HandleStunEnd();

};
