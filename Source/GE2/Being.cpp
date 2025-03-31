#include "Being.h"

#include <cassert>

#include "Camera/CameraComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/KismetSystemLibrary.h"

#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

ABeing::ABeing() : Dancing(false)
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	
	PrimaryActorTick.bCanEverTick = true;
}

void ABeing::BeginPlay()
{
	Super::BeginPlay();
}

void ABeing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABeing::MyActionPressed()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionPressed"));

	Dancing = !Dancing;
}

void ABeing::MyActionReleased()
{
//	UKismetSystemLibrary::PrintString(this, TEXT("MyActionReleased"));
}

void ABeing::MyActionDoublePressed()
{
//	UKismetSystemLibrary::PrintString(this, TEXT("MyActionDoublePressed"));
}

void ABeing::MyActionRepeated()
{
//	UKismetSystemLibrary::PrintString(this, TEXT("MyActionRepeat"));
}

void ABeing::MyAxis(float value)
{
	// FString ValueString = FString::Printf(TEXT("MyAxis: %f"), value);
	// UKismetSystemLibrary::PrintString(this, ValueString);
}

void ABeing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	assert (PlayerInputComponent != nullptr);

 	FName MyAction(TEXT("MyAction"));
 	PlayerInputComponent->BindAction(MyAction, IE_Pressed, this, &ABeing::MyActionPressed);

// 	PlayerInputComponent->BindAction(MyAction, IE_Released, this, &ABeing::MyActionReleased);
// 	PlayerInputComponent->BindAction(MyAction, IE_Repeat, this, &ABeing::MyActionRepeated);
// 	PlayerInputComponent->BindAction(MyAction, IE_DoubleClick, this, &ABeing::MyActionDoublePressed);
//
// 	FName MyAxis(TEXT("MyAxis"));
// 	PlayerInputComponent->BindAxis(MyAxis, this, &ABeing::MyAxis);
}

void ABeing::NativeShoot()
{
	FVector CurrentLocation = GetActorLocation();

	UGameplayStatics::PlaySoundAtLocation(this, ShootSound, CurrentLocation);
	
}