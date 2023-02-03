// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "PlayerCharacterAudioController.h"
#include "PlayerCharacterCameraController.h"
#include "PlayerCharacterMovementComponent.h"
#include "PlayerCharacterVFXController.h"
#include "GlobalGameJam2023/GlobalGameJam2023.h"

// Define macros
#define LOG_BLUEPRINT_REQUIRED(Object) \
const FString Name {Object->GetClass()->GetName()}; \
UE_LOG(LogPlayerCharacter, Warning, TEXT("%s is not a blueprint derived class. Please implement a blueprint derived class to allow designers to extend functionality."), *Name); \

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Construct Components.
	CameraController = CreateDefaultSubobject<UPlayerCharacterCameraController>(TEXT("Camera Controller"));
	CameraController->bWantsInitializeComponent = true;

	AudioController = CreateDefaultSubobject<UPlayerCharacterAudioController>(TEXT("Audio Controller"));
	AudioController->bWantsInitializeComponent = true;

	VFXController = CreateDefaultSubobject<UPlayerCharacterVFXController>(TEXT("VFX Controller"));
	VFXController->bWantsInitializeComponent = true;
}

// Called after construction, but before Beginplay.
void APlayerCharacter::PostInitProperties()
{
	Super::PostInitProperties();

	if(UPlayerCharacterMovementComponent* PlayerCharacterMovementComponent {Cast<UPlayerCharacterMovementComponent>(GetCharacterMovement())})
	{
		PlayerCharacterMovement = PlayerCharacterMovementComponent;
	}
	else
	{
		UE_LOG(LogPlayerCharacter, Error, TEXT("PlayerCharacter does not have PlayerCharacterMovementComponent set as its CharacterMovementComponent."))
	}
#if WITH_EDITOR
	if(!(IsRunningCommandlet() && UE::IsSavingPackage()))
	{/** Check if this instance of a PlayerCharacter is a blueprint derived class or not. */
		if(!IsBlueprintClass(this))
		{
			LOG_BLUEPRINT_REQUIRED(this);
		}
		/** Check if our components are blueprint derived classes or not. */
		if(!IsBlueprintClass(CameraController))
		{
			LOG_BLUEPRINT_REQUIRED(CameraController);
		}
		if(!IsBlueprintClass(AudioController))
		{
			LOG_BLUEPRINT_REQUIRED(AudioController);
		}
		if(!IsBlueprintClass(VFXController))
		{
			LOG_BLUEPRINT_REQUIRED(VFXController)
		}
	}
#endif
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

