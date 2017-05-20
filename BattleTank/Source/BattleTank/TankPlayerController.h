// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	//Distance that linetrace reachs - 10 km
	UPROPERTY(EditAnywhere)
	float LineTraceDistance = 1000000.0f;

	//Start the tank moving the barrel so that a shot would hit where
	void AimTowardsCrosshair();

	//Raycast towards and return if hit something
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// The porcentage of the screen that anchors the crosshair
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333f;

	//Return the value of LookDirection
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	//Return the value of the collision pointer of the aim.
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
