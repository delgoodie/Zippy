

#include "ZippyCharacterMovementComponent.h"

#include "ZippyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"


#pragma region Saved Move

UZippyCharacterMovementComponent::FSavedMove_Zippy::FSavedMove_Zippy()
{
	Saved_bWantsToSprint=0;
}

bool UZippyCharacterMovementComponent::FSavedMove_Zippy::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const
{
	const FSavedMove_Zippy* NewZippyMove = static_cast<FSavedMove_Zippy*>(NewMove.Get());

	if (Saved_bWantsToSprint != NewZippyMove->Saved_bWantsToSprint)
	{
		return false;
	}
	
	return FSavedMove_Character::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

void UZippyCharacterMovementComponent::FSavedMove_Zippy::Clear()
{
	FSavedMove_Character::Clear();

	Saved_bWantsToSprint = 0;
}

uint8 UZippyCharacterMovementComponent::FSavedMove_Zippy::GetCompressedFlags() const
{
	uint8 Result = FSavedMove_Character::GetCompressedFlags();

	if (Saved_bWantsToSprint) Result |= FLAG_Custom_0;

	return Result;
}

void UZippyCharacterMovementComponent::FSavedMove_Zippy::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
	FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);
	
	const UZippyCharacterMovementComponent* CharacterMovement = Cast<UZippyCharacterMovementComponent>(C->GetCharacterMovement());

	Saved_bWantsToSprint = CharacterMovement->Safe_bWantsToSprint;
}

void UZippyCharacterMovementComponent::FSavedMove_Zippy::PrepMoveFor(ACharacter* C)
{
	FSavedMove_Character::PrepMoveFor(C);

	UZippyCharacterMovementComponent* CharacterMovement = Cast<UZippyCharacterMovementComponent>(C->GetCharacterMovement());

	CharacterMovement->Safe_bWantsToSprint = Saved_bWantsToSprint;
}

#pragma endregion

#pragma region Client Network Prediction Data

UZippyCharacterMovementComponent::FNetworkPredictionData_Client_Zippy::FNetworkPredictionData_Client_Zippy(const UCharacterMovementComponent& ClientMovement)
: Super(ClientMovement)
{
}

FSavedMovePtr UZippyCharacterMovementComponent::FNetworkPredictionData_Client_Zippy::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_Zippy());
}

#pragma endregion

#pragma region CMC

UZippyCharacterMovementComponent::UZippyCharacterMovementComponent()
{
	NavAgentProps.bCanCrouch = true;
}

FNetworkPredictionData_Client* UZippyCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr)

	if (ClientPredictionData == nullptr)
	{
		UZippyCharacterMovementComponent* MutableThis = const_cast<UZippyCharacterMovementComponent*>(this);

		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Zippy(*this);
		MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
		MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f; 
	}
	return ClientPredictionData;
}

void UZippyCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	Safe_bWantsToSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
}

void UZippyCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

	if (MovementMode == MOVE_Walking)
	{
		if (Safe_bWantsToSprint)
		{
			MaxWalkSpeed = Sprint_MaxWalkSpeed;
		}
		else
		{
			MaxWalkSpeed = Walk_MaxWalkSpeed;
		}
	}
}

#pragma endregion

#pragma region Input

void UZippyCharacterMovementComponent::SprintPressed()
{
	Safe_bWantsToSprint = true;
}
void UZippyCharacterMovementComponent::SprintReleased()
{
	Safe_bWantsToSprint = false;
}

void UZippyCharacterMovementComponent::CrouchPressed()
{
	bWantsToCrouch = !bWantsToCrouch;
}

#pragma endregion
