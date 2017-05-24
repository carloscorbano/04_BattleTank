// TrySoftAngles 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h" //Must be left in the last include

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaTime) override;

	// How close the AI Tank is of the player
	float AcceptanceRadius = 3000;
};
