// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup=(PlayerCharacter), meta=(BlueprintSpawnableComponent))
class UPlayerCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Is Sprinting"))
	bool IsSprinting {false};
};
