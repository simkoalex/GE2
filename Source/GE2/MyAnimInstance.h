#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

UCLASS()
class GE2_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	bool CanTakeIdleToDancing() const;
	bool CanTakeDancingToIdle() const;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Dancing;

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
