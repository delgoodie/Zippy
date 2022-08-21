#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ZippyCharacterMovementComponent.generated.h"

UCLASS()
class ZIPPY_API UZippyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	class FSavedMove_Zippy : public FSavedMove_Character
	{
		typedef FSavedMove_Character Super;

		uint8 Saved_bWantsToSprint:1;

		virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;
		virtual void Clear() override;
		virtual uint8 GetCompressedFlags() const override;
		virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData) override;
		virtual void PrepMoveFor(ACharacter* C) override;
	};

	class FNetworkPredictionData_Client_Zippy : public FNetworkPredictionData_Client_Character
	{
	public:
		FNetworkPredictionData_Client_Zippy(const UCharacterMovementComponent& ClientMovement);

		typedef FNetworkPredictionData_Client_Character Super;

		virtual FSavedMovePtr AllocateNewMove() override;
	};

	UPROPERTY(EditDefaultsOnly) float Sprint_MaxWalkSpeed;
	UPROPERTY(EditDefaultsOnly) float Walk_MaxWalkSpeed;
	
	bool Safe_bWantsToSprint;

public:
	UZippyCharacterMovementComponent();
public:
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
protected:
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

public:
	UFUNCTION(BlueprintCallable) void SprintPressed();
	UFUNCTION(BlueprintCallable) void SprintReleased();
};
