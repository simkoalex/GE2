// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpinningActor.h"
#include "Engine/LevelScriptActor.h"
#include "MyLevelActor.generated.h"

UCLASS()
class GE2_API AMyLevelActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyLevelActor();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpinningActor> SpinningActorClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
