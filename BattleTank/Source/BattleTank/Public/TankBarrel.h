// TrySoftAngles 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 20.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40.0f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0.0f;
};
