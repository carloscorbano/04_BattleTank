// TrySoftAngles 2017

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto GetControlledTank = GetPawn();
	auto GetPlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!ensure(GetPlayerTank && GetControlledTank)) { return; }
	
	// Move towards the player
	MoveToActor(GetPlayerTank, AcceptanceRadius, true, true, false); //TODO check radius is in cm
		
	//Aim towards the player
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(GetPlayerTank->GetActorLocation());

	//TODO Fix Fire
	//GetControlledTank->Fire();
}
