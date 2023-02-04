// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter/PlayerCharacter.h"
#include "Weapon.generated.h"

UCLASS()
class AWeapon : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Player Character", AllowPrivateAccess = "true"))
	class APlayerCharacter* PlayerCharacter {nullptr};

	UPROPERTY(BlueprintReadWrite, Category = Default, Meta = (DisplayName = "Is In Cooldown", AllowPrivateAccess = "true"))
	bool IsInCooldown {false};

	UPROPERTY(BlueprintReadWrite, Category = Default, Meta = (DisplayName = "Is Unlocked", AllowPrivateAccess = "true"))
	bool IsUnlocked {true}; // Weapons are now unlocked by default.
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Unlock"))
	void UnlockWeapon() {IsUnlocked = true; }

	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Lock"))
	void LockWeapon() {IsUnlocked = false; }

	

};
