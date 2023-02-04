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
	class APlayerCharacter* PlayerCharacter {nullptr};

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
	void RotateToMouseCursor();

	UFUNCTION()
	void UpdatePendingMovement();
};
