
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GE2_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	void MyActionPressed();
	void MyActionReleased();
	void MyActionRepeated();
	void MyActionDoublePressed();

	void MyAxis(float value);

public:

	virtual void SetupInputComponent() override;
};
