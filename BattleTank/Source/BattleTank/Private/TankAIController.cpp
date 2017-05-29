// TrySoftAngles 2017

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GetControlledTank = Cast<ATank>(GetPawn());
	auto GetPlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(GetPlayerTank))
	{
		// Move towards the player
		MoveToActor(GetPlayerTank, AcceptanceRadius, true, true, false); //TODO check radius is in cm
		
		//Aim towards the player
		GetControlledTank->AimAt(GetPlayerTank->GetActorLocation());

		GetControlledTank->Fire();
	}
}
