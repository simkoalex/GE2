// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include <cassert>

#include "Kismet/KismetSystemLibrary.h"


void AMyPlayerController::MyActionPressed()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionPressed"));
}

void AMyPlayerController::MyActionReleased()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionReleased"));
}

void AMyPlayerController::MyActionDoublePressed()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionDoublePressed"));
}

void AMyPlayerController::MyActionRepeated()
{
	UKismetSystemLibrary::PrintString(this, TEXT("MyActionRepeat"));
}

void AMyPlayerController::MyAxis(float value)
{
	// FString ValueString = FString::Printf(TEXT("MyAxis: %f"), value);
	// UKismetSystemLibrary::PrintString(this, ValueString);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//assert (InputComponent != nullptr);
	if (InputComponent == nullptr)
	{
		return;
	}

	// FName MyAction(TEXT("MyAction"));
	// InputComponent->BindAction(MyAction, IE_Pressed, this, &AMyPlayerController::MyActionPressed);
	// InputComponent->BindAction(MyAction, IE_Released, this, &AMyPlayerController::MyActionReleased);
	// InputComponent->BindAction(MyAction, IE_Repeat, this, &AMyPlayerController::MyActionRepeated);
	// InputComponent->BindAction(MyAction, IE_DoubleClick, this, &AMyPlayerController::MyActionDoublePressed);
	//
	// FName MyAxis(TEXT("MyAxis"));
	// InputComponent->BindAxis(MyAxis, this, &AMyPlayerController::MyAxis);	
}
