// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"

#include "PlayerCharacter.h"

void APlayerCharacterController::PostInitProperties()
{
	Super::PostInitProperties();
}

void APlayerCharacterController::BeginPlay()
{
	if(GetPawn())
	{
		if(APlayerCharacter* PlayerCharacterPawn {Cast<APlayerCharacter>(GetPawn())})
		{
			PlayerCharacter = PlayerCharacterPawn;
		}
	}
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis(TEXT("LongitudinalAxis"), this, &APlayerCharacterController::HandleLongitudinalInput);
	InputComponent->BindAxis(TEXT("LateralAxis"), this, &APlayerCharacterController::HandleLateralInput);
}

void APlayerCharacterController::HandleLongitudinalInput(float Value)
{
	if (!PlayerCharacter)
	{
		return;
	}
	
	FVector CharacterLocation = PlayerCharacter->GetActorLocation();
	FVector ForwardVector = PlayerCharacter->GetCamera()->GetForwardVector();
	ForwardVector.Z = 0.f;
	ForwardVector.Normalize();
	const FVector DesiredMovementDirection = ForwardVector * Value;
	PlayerCharacter->AddMovementInput(DesiredMovementDirection, 1.f);
}

void APlayerCharacterController::HandleLateralInput(float Value)
{
	if (!PlayerCharacter)
	{
		return;
	}
	
	FVector CharacterLocation = PlayerCharacter->GetActorLocation();
	FVector Right = PlayerCharacter->GetCamera()->GetRightVector();
	Right.Z = 0.f;
	Right.Normalize();
	const FVector DesiredMovementDirection = Right * Value;
	PlayerCharacter->AddMovementInput(DesiredMovementDirection, 1.f);
}




