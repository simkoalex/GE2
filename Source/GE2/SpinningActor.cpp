#include "SpinningActor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetSystemLibrary.h"

ASpinningActor::ASpinningActor() :
	StaticMeshComponent(nullptr)
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
}

void ASpinningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UKismetSystemLibrary::PrintString(this, TEXT("Tick"));
}

void ASpinningActor::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, TEXT("BeginPlay"));
}

