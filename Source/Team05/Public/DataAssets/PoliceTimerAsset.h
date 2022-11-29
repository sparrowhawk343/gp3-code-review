// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PoliceTimerAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TEAM05_API UPoliceTimerAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentTimer = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTimerCounting = true;

	UFUNCTION(BlueprintCallable)
	void ResetObj();

	UFUNCTION(BlueprintCallable)
	void SetObj999();
};
