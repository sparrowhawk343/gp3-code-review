// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WMaths.generated.h"

/**
 * 
 */
UCLASS()
class TEAM05_API UWMaths : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "WMath")
	static FRotator Rotation8Ways(float Right, float Forward, FVector LastRotationVector, FVector & OutLastRotationVector);
	
	UFUNCTION(BlueprintPure, Category = "WMath")
	static FVector EmtyTestThing(FVector Vector, FRotator Rotator, bool bYesNo, int iInteger, FString sText);

};

