// TrySoftAngles 2017

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledIATank = GetControlledPawn();
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("IA Tank reporting targetting to: %s"), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("IA Tank reporting don't have a target."));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO Move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if is in range
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

