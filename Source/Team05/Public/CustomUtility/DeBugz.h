// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeBugz.generated.h"

/**
 * 
 */
UCLASS()
class TEAM05_API UDeBugz : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	constexpr static int LineThickness = 3;

	static void PrintText(FString String);
	static void PrintText(FString String, float Time);
	static void PrintText(FString String, FColor Color);
	static void PrintText(FString String, float Time, FColor Color);

	static void DrawLine(const UWorld* World, FVector Start, FVector End);
	static void DrawLine(const UWorld* World, FVector Start, FVector End, FColor Color);
	static void DrawSphere(const UWorld* World, FVector Center, float Radius, FColor Color);
};
