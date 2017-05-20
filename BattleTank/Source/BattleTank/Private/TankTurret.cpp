// TrySoftAngles 2017

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Given a max translate speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, +1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0.0f, RawNewRotation, 0.0f));
}