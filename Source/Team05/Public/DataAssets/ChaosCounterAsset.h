// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChaosCounterAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TEAM05_API UChaosCounterAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CounterMaxValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CounterCurrent = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PercentageFull = 75;
	
	UFUNCTION(BlueprintCallable)
	void Register(int value);

	UFUNCTION(BlueprintCallable)
	void Deregister(int value);

	UFUNCTION(BlueprintCallable)
	void ResetObj();
	
	UFUNCTION(BlueprintPure)
	float GetPercent();
};
