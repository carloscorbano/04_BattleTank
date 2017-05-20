// TrySoftAngles 2017

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h" //Must be left in the last include

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

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
