#pragma once

#include "CoreMinimal.h"
#include "Zippy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ZippyCharacterMovementComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDashStartDelegate);

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_None			UMETA(Hidden),
	CMOVE_Slide			UMETA(DisplayName = "Slide"),
	CMOVE_Prone			UMETA(DisplayName = "Prone"),
	CMOVE_MAX			UMETA(Hidden),
};


UCLASS()
class ZIPPY_API UZippyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	class FSavedMove_Zippy : public FSavedMove_Character
	{
	public:
		enum CompressedFlags
		{
			FLAG_Sprint			= 0x10,
			FLAG_Dash			= 0x20,
			FLAG_Custom_2		= 0x40,
			FLAG_Custom_3		= 0x80,
		};
		
		// Flags
		uint8 Saved_bPressedZippyJump:1;
		uint8 Saved_bWantsToSprint:1;
		uint8 Saved_bWantsToDash:1;

		// Other Variables
		uint8 Saved_bHadAnimRootMotion:1;
		uint8 Saved_bTransitionFinished:1;
		uint8 Saved_bPrevWantsToCrouch:1;
		uint8 Saved_bWantsToProne:1;

		FSavedMove_Zippy();

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

	// Parameters
		UPROPERTY(EditDefaultsOnly) float MaxSprintSpeed=750.f;

		// Slide
		UPROPERTY(EditDefaultsOnly) float MinSlideSpeed=400.f;
		UPROPERTY(EditDefaultsOnly) float MaxSlideSpeed=400.f;
		UPROPERTY(EditDefaultsOnly) float SlideEnterImpulse=400.f;
		UPROPERTY(EditDefaultsOnly) float SlideGravityForce=4000.f;
		UPROPERTY(EditDefaultsOnly) float SlideFrictionFactor=.06f;
		UPROPERTY(EditDefaultsOnly) float BrakingDecelerationSliding=1000.f;

		// Prone
		UPROPERTY(EditDefaultsOnly) float ProneEnterHoldDuration=.2f;
		UPROPERTY(EditDefaultsOnly) float ProneSlideEnterImpulse=300.f;
		UPROPERTY(EditDefaultsOnly) float MaxProneSpeed=300.f;
		UPROPERTY(EditDefaultsOnly) float BrakingDecelerationProning=2500.f;

		// Dash
		UPROPERTY(EditDefaultsOnly) float DashCooldownDuration=1.f;
		UPROPERTY(EditDefaultsOnly) float AuthDashCooldownDuration=.9f;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* DashMontage;

		// Mantle
		UPROPERTY(EditDefaultsOnly) float MantleMaxDistance = 200;
    	UPROPERTY(EditDefaultsOnly) float MantleReachHeight = 50;
    	UPROPERTY(EditDefaultsOnly) float MinMantleDepth = 30;
    	UPROPERTY(EditDefaultsOnly) float MantleMinWallSteepnessAngle = 75;
    	UPROPERTY(EditDefaultsOnly) float MantleMaxSurfaceAngle = 40;
    	UPROPERTY(EditDefaultsOnly) float MantleMaxAlignmentAngle = 45;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* TallMantleMontage;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* TransitionTallMantleMontage;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* ProxyTallMantleMontage;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* ShortMantleMontage;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* TransitionShortMantleMontage;
		UPROPERTY(EditDefaultsOnly) UAnimMontage* ProxyShortMantleMontage;
	
	// Transient
		UPROPERTY(Transient) AZippyCharacter* ZippyCharacterOwner;

		// Flags
		bool Safe_bWantsToSprint;
		bool Safe_bWantsToProne;
		bool Safe_bWantsToDash;

		bool Safe_bHadAnimRootMotion;
		bool Safe_bPrevWantsToCrouch;

		float DashStartTime;
		FTimerHandle TimerHandle_EnterProne;
		FTimerHandle TimerHandle_DashCooldown;

		bool Safe_bTransitionFinished;
		TSharedPtr<FRootMotionSource_MoveToForce> TransitionRMS;
		UPROPERTY(Transient) UAnimMontage* TransitionQueuedMontage;
		float TransitionQueuedMontageSpeed;
		int TransitionRMS_ID;
	

	// Replication
		UPROPERTY(ReplicatedUsing=OnRep_Dash) bool Proxy_bDash;

		UPROPERTY(ReplicatedUsing=OnRep_ShortMantle) bool Proxy_bShortMantle;
		UPROPERTY(ReplicatedUsing=OnRep_TallMantle) bool Proxy_bTallMantle;

	// Delegates
public:
	UPROPERTY(BlueprintAssignable) FDashStartDelegate DashStartDelegate;

public:
	UZippyCharacterMovementComponent();

	// Actor Component
protected:
	virtual void InitializeComponent() override;
	// Character Movement Component
public:
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual bool IsMovingOnGround() const override;
	virtual bool CanCrouchInCurrentState() const override;
	virtual float GetMaxSpeed() const override;
	virtual float GetMaxBrakingDeceleration() const override;
	
protected:
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
public:
	virtual void UpdateCharacterStateBeforeMovement(float DeltaSeconds) override;
	virtual void UpdateCharacterStateAfterMovement(float DeltaSeconds) override;
protected:
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

	// Slide
private:
	void EnterSlide(EMovementMode PrevMode, ECustomMovementMode PrevCustomMode);
	void ExitSlide();
	bool CanSlide() const;
	void PhysSlide(float deltaTime, int32 Iterations);

	// Prone
private:
	void OnTryEnterProne() { Safe_bWantsToProne = true; }
	UFUNCTION(Server, Reliable) void Server_EnterProne();
	
	void EnterProne(EMovementMode PrevMode, ECustomMovementMode PrevCustomMode);
	void ExitProne();
	bool CanProne() const;
	void PhysProne(float deltaTime, int32 Iterations);

	// Dash
private:
	void OnDashCooldownFinished();

	bool CanDash() const;
	void PerformDash();

	// Vault
private:
	bool TryMantle();
	FVector GetMantleStartLocation(FHitResult FrontHit, FHitResult SurfaceHit, bool bTallMantle) const;

	// Helpers
private:
	bool IsServer() const;
	float CapR() const;
	float CapHH() const;
	
	// Interface
public:
	UFUNCTION(BlueprintCallable) void SprintPressed();
	UFUNCTION(BlueprintCallable) void SprintReleased();

	UFUNCTION(BlueprintCallable) void CrouchPressed();
	UFUNCTION(BlueprintCallable) void CrouchReleased();
	
	UFUNCTION(BlueprintCallable) void DashPressed();
	UFUNCTION(BlueprintCallable) void DashReleased();


	UFUNCTION(BlueprintPure) bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;
	UFUNCTION(BlueprintPure) bool IsMovementMode(EMovementMode InMovementMode) const;

	// Proxy Replication
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
private:
	UFUNCTION() void OnRep_Dash();
	UFUNCTION() void OnRep_ShortMantle();
	UFUNCTION() void OnRep_TallMantle();
};