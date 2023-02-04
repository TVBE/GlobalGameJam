// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class AGun : public AWeapon
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Get Gun Trace"))
	FHitResult LineTraceFromPlayerToCursor(float Deviation);

	/** Returns the mouse cursor world location with some deviation to simulate accuracy loss. */
	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Get Gun Trace Target"))
	FVector GetCursorLocationWithDeviation(float Deviation, APlayerController* PlayerController);
	
};
