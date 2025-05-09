#include "BaseActor.h"

#include "Engine/DamageEvents.h"


float ABaseActor::InternalTakePointDamage(float Damage, FPointDamageEvent const& PointDamageEvent,
                                          AController* EventInstigator, AActor* DamageCauser)
{

	UDamageType const * const DamageType = PointDamageEvent.DamageTypeClass ?
		PointDamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();

	return DoInternalTakePointDamage(Damage, DamageType,
		PointDamageEvent.ShotDirection, PointDamageEvent.HitInfo, EventInstigator, DamageCauser);
}

ABaseActor::ABaseActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

float ABaseActor::DoInternalTakePointDamage_Implementation(float Damage, UDamageType const* const DamageType,
	FVector const& ShotDirection, FHitResult const& hit, AController* EventInstigator, AActor* DamageCauser)
{
	return Damage;
}
