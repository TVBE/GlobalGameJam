// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"

#include "PlayerCharacter.h"
#include "PlayerCharacterMovementComponent.h"

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

	InputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &APlayerCharacterController::HandleSprintActionPressed);
	InputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &APlayerCharacterController::HandleSprintActionReleased);
}

void APlayerCharacterController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	RotateToMouseCursor();
	UpdatePendingMovement();
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



void APlayerCharacterController::RotateToMouseCursor()
{
	if (GetPawn())
	{
		FVector MouseLocation, MouseDirection;
		this->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
        
		const FVector PlayerLocation {GetPawn()->GetActorLocation()};
		const FVector TargetLocation {MouseLocation + MouseDirection * (PlayerLocation - MouseLocation).Size()};
        
		FRotator TargetRotation = (TargetLocation - PlayerLocation).Rotation();
		TargetRotation.Pitch = 0.0f;
		TargetRotation.Roll = 0.0f;
        
		GetPawn()->SetActorRotation(TargetRotation);
	}
}

void APlayerCharacterController::UpdatePendingMovement()
{
	if(PlayerCharacter && PlayerCharacter->GetPlayerCharacterMovement() && PlayerCharacter->GetPlayerCharacterMovement()->IsSprinting)
	{
		const FVector ActorForwardVector = PlayerCharacter->GetActorForwardVector();
		const FVector ActorVelocity = PlayerCharacter->GetVelocity();
		const FVector ActorRightVector = PlayerCharacter->GetActorRightVector();

		if(!(FVector::DotProduct(ActorForwardVector, ActorVelocity) > 0.0f &&
		FMath::Abs(FVector::DotProduct(ActorRightVector, ActorVelocity)) <=
		FVector::DotProduct(ActorForwardVector, ActorVelocity)))
		{
			HandleSprintActionReleased();
		}
	}
}

void APlayerCharacterController::HandleSprintActionPressed()
{
	if(PlayerCharacter && PlayerCharacter->CanSprint() && PlayerCharacter->GetPlayerCharacterMovement())
	{
		if(!PlayerCharacter->GetPlayerCharacterMovement()->IsSprinting)
		{
			const FVector ActorForwardVector = PlayerCharacter->GetActorForwardVector();
			const FVector ActorVelocity = PlayerCharacter->GetVelocity();
			const FVector ActorRightVector = PlayerCharacter->GetActorRightVector();

			if(FVector::DotProduct(ActorForwardVector, ActorVelocity) > 0.0f &&
			FMath::Abs(FVector::DotProduct(ActorRightVector, ActorVelocity)) <=
			FVector::DotProduct(ActorForwardVector, ActorVelocity))
			{
				PlayerCharacter->GetPlayerCharacterMovement()->IsSprinting = true;
				PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = PlayerCharacter->GetConfiguration().SprintSpeed;
			}
			
		}
	}
}

void APlayerCharacterController::HandleSprintActionReleased()
{
	if(PlayerCharacter && PlayerCharacter->GetPlayerCharacterMovement())
	{
		if(PlayerCharacter->GetPlayerCharacterMovement()->IsSprinting)
		{
			PlayerCharacter->GetPlayerCharacterMovement()->IsSprinting = false;
			PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = PlayerCharacter->GetConfiguration().WalkSpeed;
		}
	}
}

void APlayerCharacterController::HandleAttackActionPressed()
{
	if(PlayerCharacter)
	{
		PlayerCharacter->EventFire(true);
	}
}

void APlayerCharacterController::HandleAttackActionReleased()
{
	if(PlayerCharacter)
	{
		PlayerCharacter->EventFire(false);
	}
}





