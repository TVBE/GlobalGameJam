// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterCameraController.h"

#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GlobalGameJam2023/GlobalGameJam2023.h"

// Sets default values for this component's properties
UPlayerCharacterCameraController::UPlayerCharacterCameraController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerCharacterCameraController::InitializeComponent()
{
	Super::InitializeComponent();
	
	if(GetOwner())
	{
		if(APlayerCharacter* PlayerPawn {Cast<APlayerCharacter>(GetOwner())})
		{
			PlayerCharacter = PlayerPawn;
		}
		if(UCineCameraComponent* CineCamera {Cast<APlayerCharacter>(GetOwner())->GetCamera()})
		{
			Camera = CineCamera;
		}
		if(USpringArmComponent* SpringArmComponent {Cast<APlayerCharacter>(GetOwner())->GetCameraArm()})
		{
			CameraArm = SpringArmComponent;
			TargetRotation = CameraArm->GetComponentRotation();
		}
		else
		{
			UE_LOG(LogPlayerCameraController, Error, TEXT("Could not get pointer to CameraArm. "));
		}
	}
}

// Called when the game starts
void UPlayerCharacterCameraController::BeginPlay()
{
	Super::BeginPlay();
	

	// ...
	
}


// Called every frame
void UPlayerCharacterCameraController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateCameraRotation();
}

void UPlayerCharacterCameraController::UpdateCameraRotation()
{
	CameraArm->SetWorldRotation(TargetRotation);
}

