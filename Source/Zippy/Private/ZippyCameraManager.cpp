#include "ZippyCameraManager.h"

#include "ZippyCharacter.h"
#include "ZippyCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"


AZippyCameraManager::AZippyCameraManager()
{
}

void AZippyCameraManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
{
	Super::UpdateViewTarget(OutVT, DeltaTime);

	if (AZippyCharacter* ZippyCharacter = Cast<AZippyCharacter>(GetOwningPlayerController()->GetPawn()))
	{
		UZippyCharacterMovementComponent* ZMC = ZippyCharacter->GetZippyCharacterMovement();
		FVector TargetCrouchOffset = FVector(
			0,
			0,
			ZMC->GetCrouchedHalfHeight() - ZippyCharacter->GetClass()->GetDefaultObject<ACharacter>()->GetCapsuleComponent()->GetScaledCapsuleHalfHeight()
		);
		FVector Offset = FMath::Lerp(FVector::ZeroVector, TargetCrouchOffset, FMath::Clamp(CrouchBlendTime / CrouchBlendDuration, 0.f, 1.f));

		if (ZMC->IsCrouching())
		{
			CrouchBlendTime = FMath::Clamp(CrouchBlendTime + DeltaTime, 0.f, CrouchBlendDuration);
			Offset -= TargetCrouchOffset;
		}
		else
		{
			CrouchBlendTime = FMath::Clamp(CrouchBlendTime - DeltaTime, 0.f, CrouchBlendDuration);
		}

		OutVT.POV.Location += Offset;
	}
}
