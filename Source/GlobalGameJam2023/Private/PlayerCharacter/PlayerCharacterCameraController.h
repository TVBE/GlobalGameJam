// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCharacterCameraController.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(PlayerCharacter), meta=(BlueprintSpawnableComponent))
class UPlayerCharacterCameraController : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY()
	class USpringArmComponent* CameraArm {nullptr};
	
	UPROPERTY()
	FRotator TargetRotation;
	
public:	
	// Sets default values for this component's properties
	UPlayerCharacterCameraController();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void InitializeComponent() override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Called on Tick.
	UFUNCTION()
	void UpdateCameraRotation();
	

		
};
