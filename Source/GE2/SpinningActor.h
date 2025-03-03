#pragma once

#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include "GameFramework/RotatingMovementComponent.h"
#include "SpinningActor.generated.h"

UCLASS()
class ASpinningActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *SubComponent;

	UPROPERTY(EditAnywhere)
	URotatingMovementComponent *MovementComponent;


public:
	ASpinningActor();

	UPROPERTY(EditDefaultsOnly)
	int MyProperty = 10;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};