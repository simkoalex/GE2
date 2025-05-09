#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class GE2_API ABaseActor : public AActor
{
	GENERATED_BODY()

protected:
	virtual float InternalTakePointDamage(float Damage, FPointDamageEvent const& PointDamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

public:
	ABaseActor();

	UFUNCTION(BlueprintNativeEvent)
	float DoInternalTakePointDamage(float Damage, UDamageType const * const DamageType,
		FVector const &ShotDirection, FHitResult const &hit, AController* EventInstigator, AActor* DamageCauser);
	
};
