// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystem/AC_InteractableObjectComponent.h"
#include "AC_Pickup.generated.h"

/**
 * 
 */
UCLASS()
class TEAM05_API UAC_Pickup : public UAC_InteractableObjectComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetupCollisions();
	UPROPERTY(EditAnywhere)
	float ThrowForceMultiplier;
	UPROPERTY(BlueprintReadWrite)
	bool BeingThrown = false;
};
