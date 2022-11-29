// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Protection.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TEAM05_API UProtection : public UDataAsset
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Protection = true;
};
