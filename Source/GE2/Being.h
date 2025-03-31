#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Being.generated.h"

UCLASS()
class GE2_API ABeing : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	void MyActionPressed();
	void MyActionReleased();
	void MyActionRepeated();
	void MyActionDoublePressed();

	void MyAxis(float value);
	
protected:
	virtual void BeginPlay() override;
	
public:
	ABeing();

	UPROPERTY(VisibleAnywhere)
	bool Dancing;

	UPROPERTY(EditAnywhere)
	USoundBase *ShootSound;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void NativeShoot();
};
