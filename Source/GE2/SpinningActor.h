#pragma once

#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include "GameFramework/RotatingMovementComponent.h"
#include "SpinningActor.generated.h"

UCLASS(Blueprintable)
class ASpinningActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *SubComponent;

	UPROPERTY(EditAnywhere)
	URotatingMovementComponent *MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category="Spinning",
		meta=(AllowPrivateAccess="True"))
	int NumberOfSpins;

	float LastYaw;

	FString Description;
	
public:
	ASpinningActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spinning|B",
		meta=(DisplayName="My Threshold", ExposeOnSpawn=true))
	int Threshold;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpin();

	UFUNCTION(BlueprintNativeEvent)
	void OnThresholdReached();

	UFUNCTION(BlueprintCallable)
	void ResetSpinning();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetDescription(UPARAM(Ref) FString &NewDescription);

	UFUNCTION(BlueprintCallable)
	int GetNumberOfSpins();

	virtual void OnConstruction(const FTransform& Transform) override;
};