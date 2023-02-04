// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

FHitResult AGun::LineTraceFromPlayerToCursor(float Deviation)
{
	if(GetWorld())
	{
		if(APlayerController* PlayerController {GetWorld()->GetFirstPlayerController()})
		{
			FHitResult HitResult;
			FVector Start = PlayerController->GetPawn()->GetActorLocation();
			FVector End = GetCursorLocationWithDeviation(Deviation, PlayerController);
			FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("LineTrace")), true, PlayerController->GetPawn());
			GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams);
			return HitResult;
		}
	}
	return FHitResult();
}

FVector AGun::GetCursorLocationWithDeviation(float Deviation, APlayerController* PlayerController)
{
	FVector MouseLocation, MouseDirection;
	PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
	
	FVector RandomVector = FMath::VRand();
	RandomVector *= Deviation;
	MouseLocation += RandomVector;
	return MouseLocation;
}






