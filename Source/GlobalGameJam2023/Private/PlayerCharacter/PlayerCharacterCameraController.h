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
	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Player Character", AllowPrivateAccess = "true"))
	class APlayerCharacter* PlayerCharacter {nullptr};

	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Camera", AllowPrivateAccess = "true"))
	class UCineCameraComponent* Camera {nullptr};
	
	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Camera Arm", AllowPrivateAccess = "true"))
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
