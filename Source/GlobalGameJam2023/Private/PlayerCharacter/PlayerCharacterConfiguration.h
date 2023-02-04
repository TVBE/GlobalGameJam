// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterConfiguration.generated.h"

/** Structure that defines the player characters configuration and behavior.
 *	This class provides a convenient way for designers to tweak the player settings, and can be stored inside a data asset.*/
USTRUCT(BlueprintType)
struct FPlayerCharacterConfiguration
{
	GENERATED_USTRUCT_BODY()
	
	/** Defines the default movement speed.*/
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = General, Meta = (DisplayName = "Default Movement Speed", ClampMin = "0", ClampMax = "400", UiMin = "0", UIMax = "400"))
	float WalkSpeed {300.f};
	
	/** Defines the movement speed when sprinting. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Sprinting, Meta = (DisplayName = "Sprint Speed", EditCondition= "IsSprintingEnabled", ClampMin = "400", ClampMax = "800", UiMin = "400", UIMax = "800"))
	float SprintSpeed {600.f};
	
	/** Constructor with default values. */
	FPlayerCharacterConfiguration()
	{
	
	}
};
