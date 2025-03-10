#include "SpinningActor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ASpinningActor::ASpinningActor() :
	StaticMeshComponent(nullptr),
	NumberOfSpins(0),
	LastYaw(0)
{

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	if (StaticMeshComponent == nullptr)
	{
		throw std::runtime_error("Failed to create StaticMeshComponent");
	}
	
	SetRootComponent(StaticMeshComponent);

	UStaticMesh *Sphere = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));
	if (Sphere)
	{
		StaticMeshComponent->SetStaticMesh(Sphere);		
	}

	SubComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubStaticMeshComponent"));
	SubComponent->SetupAttachment(StaticMeshComponent);
	SubComponent->SetRelativeLocation(FVector(0.0, 0.0,100.0));
	SubComponent->SetStaticMesh(Sphere);

	MovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MovementComponent"));

	PrimaryActorTick.bCanEverTick = true;

	LastYaw = GetActorRotation().Yaw;
}

void ASpinningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CurrentYaw = GetActorRotation().Yaw;
	if (CurrentYaw < LastYaw)
	{
		++NumberOfSpins;
		OnSpin();
		if (NumberOfSpins == Threshold)
		{
			OnThresholdReached();
		}
	}
	LastYaw = CurrentYaw;
}

void ASpinningActor::ResetSpinning()
{
	NumberOfSpins = 0;
	LastYaw = GetActorRotation().Yaw;
}

void ASpinningActor::OnThresholdReached_Implementation()
{
	UKismetSystemLibrary::PrintString(this, TEXT("OnThresholdReached()"));
}

void ASpinningActor::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, TEXT("BeginPlay"));
}

void ASpinningActor::SetDescription(FString& NewDescription)
{
	Description = NewDescription;
}

int ASpinningActor::GetNumberOfSpins()
{
	return NumberOfSpins;
}
