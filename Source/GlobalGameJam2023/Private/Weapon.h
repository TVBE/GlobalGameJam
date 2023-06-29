// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PlayerCharacter/PlayerCharacter.h"
#include "Weapon.generated.h"


UENUM(BlueprintType)
enum class EWeaponType : uint8 {
	DEFAULT UMETA(DisplayName = "DEFAULT"),
	HAMMER UMETA(DisplayName = "Hammer"),
	PISTOL UMETA(DisplayName = "Pistol"),
	GRENADE UMETA(DisplayName = "Grenade"),
	MINE UMETA(DisplayName = "Mine"),
	TURRET UMETA(DisplayName = "Turret")
};

UENUM(BlueprintType)
enum class EWeaponBehaviour : uint8 {
	MELEE UMETA(DisplayName = "Melee"),
	SINGLE_FIRE UMETA(DisplayName = "Single Fire"),
	AUTOMATIC_FIRE UMETA(DisplayName = "Automatic Fire"),
	THROWABLE UMETA(DisplayName = "Throwable"),
	PLACEABLE UMETA(DisplayName = "Placeable")
};

UCLASS()
class AWeapon : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category = Default, Meta = (DisplayName = "Player Character", AllowPrivateAccess = "true"))
		class APlayerCharacter* PlayerCharacter{ nullptr };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		EWeaponType WeaponType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		EWeaponBehaviour WeaponBehaviour;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		FString WeaponDisplayName = "DefaultWeapon";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		UTexture* WeaponIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		float WeaponDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (Category = "WeaponData", AllowPrivateAccess = "true"))
		float CooldownTime;

	UPROPERTY(BlueprintReadWrite, Category = "WeaponLogic", Meta = (DisplayName = "Is In Cooldown", AllowPrivateAccess = "true"))
		bool IsInCooldown{ false };

	UPROPERTY(BlueprintReadWrite, Category = "WeaponLogic", Meta = (DisplayName = "Is Unlocked", AllowPrivateAccess = "true"))
		bool IsUnlocked{ true }; // Weapons are now unlocked by default.

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
		void UnlockWeapon() { IsUnlocked = true; }

	UFUNCTION(BlueprintCallable, Category = Default, Meta = (DisplayName = "Lock"))
		void LockWeapon() { IsUnlocked = false; }

};
