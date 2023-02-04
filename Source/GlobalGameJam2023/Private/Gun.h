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
	UFUNCTION(BlueprintPure, Category = Default, Meta = (DisplayName = "Get Gun Trace"))
	FHitResult GetGunTrace(float Accuracy);
	
};
