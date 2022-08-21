#pragma once

#include "CoreMinimal.h"
#include "Zippy.h"
#include "ZippyCharacter.generated.h"

UCLASS(config=Game)
class AZippyCharacter : public ACharacter
{
	GENERATED_BODY()

	// Components
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Movement) class UZippyCharacterMovementComponent* ZippyCharacterMovementComponent;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) UCameraComponent* FollowCamera;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input) float TurnRateGamepad;

public:
	AZippyCharacter(const FObjectInitializer& ObjectInitializer);

	// Input
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

