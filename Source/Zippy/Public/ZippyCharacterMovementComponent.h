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
	CMOVE_WallRun		UMETA(DisplayName = "Wall Run"),
	CMOVE_Hang			UMETA(DisplayName = "Hang"),
	CMOVE_Climb			UMETA(DisplayName = "Climb"),
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
		uint8 Saved_bWallRunIsRight:1;


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


	// Wall Run
	UPROPERTY(EditDefaultsOnly) float MinWallRunSpeed=200.f;
	UPROPERTY(EditDefaultsOnly) float MaxWallRunSpeed=800.f;
	UPROPERTY(EditDefaultsOnly) float MaxVerticalWallRunSpeed=200.f;
	UPROPERTY(EditDefaultsOnly) float WallRunPullAwayAngle=75;
	UPROPERTY(EditDefaultsOnly) float WallAttractionForce = 200.f;
	UPROPERTY(EditDefaultsOnly) float MinWallRunHeight=50.f;
	UPROPERTY(EditDefaultsOnly) UCurveFloat* WallRunGravityScaleCurve;
	UPROPERTY(EditDefaultsOnly) float WallJumpOffForce = 300.f;

	// Hang
	UPROPERTY(EditDefaultsOnly) UAnimMontage* TransitionHangMontage;
	UPROPERTY(EditDefaultsOnly) UAnimMontage* WallJumpMontage;
	UPROPERTY(EditDefaultsOnly) float WallJumpForce = 400.f;

	// Climb
	UPROPERTY(EditDefaultsOnly) float MaxClimbSpeed = 300.f;
	UPROPERTY(EditDefaultsOnly) float BrakingDecelerationClimbing = 1000.f;
	UPROPERTY(EditDefaultsOnly) float ClimbReachDistance = 200.f;

	
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
		FString TransitionName;
		UPROPERTY(Transient) UAnimMontage* TransitionQueuedMontage;
		float TransitionQueuedMontageSpeed;
		int TransitionRMS_ID;

		bool Safe_bWallRunIsRight;

	float AccumulatedClientLocationError=0.f;


	int TickCount=0;
	int CorrectionCount=0;
	int TotalBitsSent=0;
	

	// Replication
		UPROPERTY(ReplicatedUsing=OnRep_Dash) bool Proxy_bDash;

		UPROPERTY(ReplicatedUsing=OnRep_ShortMantle) bool Proxy_bShortMantle;
		UPROPERTY(ReplicatedUsing=OnRep_TallMantle) bool Proxy_bTallMantle;

	// Delegates
public:
	UPROPERTY(BlueprintAssignable) FDashStartDelegate DashStartDelegate;

public:
	UZippyCharacterMovementComponent();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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

	virtual bool CanAttemptJump() const override;
	virtual bool DoJump(bool bReplayingMoves) override;
	
protected:
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual void OnClientCorrectionReceived(FNetworkPredictionData_Client_Character& ClientData, float TimeStamp, FVector NewLocation, FVector NewVelocity, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode, FVector ServerGravityDirection) override;
public:
	virtual void UpdateCharacterStateBeforeMovement(float DeltaSeconds) override;
	virtual void UpdateCharacterStateAfterMovement(float DeltaSeconds) override;
protected:
	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

	virtual bool ServerCheckClientError(float ClientTimeStamp, float DeltaTime, const FVector& Accel, const FVector& ClientWorldLocation, const FVector& RelativeClientLocation, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode) override;

	FNetBitWriter ZippyServerMoveBitWriter;
	
	virtual void CallServerMovePacked(const FSavedMove_Character* NewMove, const FSavedMove_Character* PendingMove, const FSavedMove_Character* OldMove) override;
	
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

	// Wall Run
private:
	bool TryWallRun();
	void PhysWallRun(float deltaTime, int32 Iterations);

// Climb
private:
	bool TryHang();

	bool TryClimb();
	void PhysClimb(float deltaTime, int32 Iterations);
	
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
	
	UFUNCTION(BlueprintCallable) void ClimbPressed();
	UFUNCTION(BlueprintCallable) void ClimbReleased();

	UFUNCTION(BlueprintPure) bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;
	UFUNCTION(BlueprintPure) bool IsMovementMode(EMovementMode InMovementMode) const;

	UFUNCTION(BlueprintPure) bool IsWallRunning() const { return IsCustomMovementMode(CMOVE_WallRun); }
	UFUNCTION(BlueprintPure) bool WallRunningIsRight() const { return Safe_bWallRunIsRight; }
	UFUNCTION(BlueprintPure) bool IsHanging() const { return IsCustomMovementMode(CMOVE_Hang); }
	UFUNCTION(BlueprintPure) bool IsClimbing() const { return IsCustomMovementMode(CMOVE_Climb); }

	// Proxy Replication
public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
private:
	UFUNCTION() void OnRep_Dash();
	UFUNCTION() void OnRep_ShortMantle();
	UFUNCTION() void OnRep_TallMantle();
};