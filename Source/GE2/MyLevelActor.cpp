// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelActor.h"

#include "SpinningActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AMyLevelActor::AMyLevelActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// UBlueprint *Blueprint = LoadObject<UBlueprint>(nullptr, TEXT("/Game/BPSPinningActor"));
	// UClass *Meta = Blueprint->GeneratedClass;	
}

// Called when the game starts or when spawned
void AMyLevelActor::BeginPlay()
{
	Super::BeginPlay();

	UKismetSystemLibrary::PrintString(this,TEXT("MyLevelActor"));


	
	//UClass *SpinningActorClass = ASpinningActor::StaticClass();
	if (SpinningActorClass == nullptr)
	{
		return;
	}

	
	UWorld* World = GetWorld();
	FTransform SpinningTransform;
	SpinningTransform.SetLocation(FVector(0, 0, 100));
	
	if (ASpinningActor *Actor = World->SpawnActorDeferred<ASpinningActor>(SpinningActorClass, SpinningTransform))
	{
		Actor->Threshold = 7;
		/// sadsds
		UGameplayStatics::FinishSpawningActor(Actor, SpinningTransform);
	}
}

// Called every frame
void AMyLevelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

