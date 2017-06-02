// TrySoftAngles 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h" //Must be left in the last include

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
		
protected:
	// How close the AI Tank is of the player
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 80000.0f;

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnTankDeath();
};
