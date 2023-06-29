// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"



/**
 *
 */
UCLASS()
class APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY()
		class APlayerCharacter* PlayerCharacter{ nullptr };

	UPROPERTY()
		bool IsSprintPending{ false };

public:
	virtual void PostInitProperties() override;
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UFUNCTION()
		void HandleLongitudinalInput(float Value);

	UFUNCTION()
		void HandleLateralInput(float Value);

	UFUNCTION()
		void HandleSprintActionPressed();

	UFUNCTION()
		void HandleSprintActionReleased();

	UFUNCTION()
		void HandleAttackActionPressed();

	UFUNCTION()
		void HandleAttackActionReleased();

	UFUNCTION()
		void HandleWeaponsSwitchNext();

	UFUNCTION()
		void HandleWeaponsSwitchPrevious();

	UFUNCTION()
		void HandleControllerVerticalCursor(float value);

	UFUNCTION()
		void HandleControllerHorizontalCursor(float value);

	UFUNCTION()
		void RotateToMouseCursor();

	UFUNCTION()
		void UpdatePendingMovement();

	UFUNCTION()
		void StartSprinting();

	UFUNCTION()
		void StopSprinting();

	UFUNCTION()
		bool CanSprint();

};
