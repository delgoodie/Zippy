#pragma once

#include "CoreMinimal.h"
#include "Zippy.h"
#include "GameFramework/Character.h"
#include "ZippyCharacter.generated.h"

UCLASS(config=Game)
class AZippyCharacter : public ACharacter
{
	GENERATED_BODY()

	// Components
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Movement) UZippyCharacterMovementComponent* ZippyCharacterMovementComponent;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) UCameraComponent* FollowCamera;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input) float TurnRateGamepad;

public:
	bool bPressedZippyJump;
	
public:
	AZippyCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void Jump() override;
	virtual void StopJumping() override;

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
	UFUNCTION(BlueprintPure) FORCEINLINE UZippyCharacterMovementComponent* GetZippyCharacterMovement() const { return ZippyCharacterMovementComponent; }

	FCollisionQueryParams GetIgnoreCharacterParams() const;

};

