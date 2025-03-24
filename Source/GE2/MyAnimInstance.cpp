#include "Being.h"
#include "MyAnimInstance.h"

bool UMyAnimInstance::CanTakeIdleToDancing() const
{
	return Dancing;
}

bool UMyAnimInstance::CanTakeDancingToIdle() const
{
	return !Dancing;
}

void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	FName DefaultMachine(TEXT("DefaultMachine"));
	FName Idle(TEXT("Idle"));
	FName Dancing(TEXT("Dancing"));

	FCanTakeTransition CanTakeIdleToDancing;
	CanTakeIdleToDancing.BindUObject(this, &UMyAnimInstance::CanTakeIdleToDancing);
	AddNativeTransitionBinding(DefaultMachine, Idle, Dancing, CanTakeIdleToDancing);

	FCanTakeTransition CanTakeDancingToIdle;
	CanTakeDancingToIdle.BindUObject(this, &UMyAnimInstance::CanTakeDancingToIdle);
	AddNativeTransitionBinding(DefaultMachine, Dancing, Idle, CanTakeDancingToIdle);
}


void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	ABeing *Being = Cast<ABeing>(TryGetPawnOwner());
	if (Being == nullptr)
	{
		return;
	}
	
	Dancing = Being->Dancing;
}
