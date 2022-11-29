// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomUtility/DeBugz.h"
#ifdef WITH_EDITOR
#include <Runtime/Engine/Public/DrawDebugHelpers.h>
#endif

void UDeBugz::PrintText(FString String)
{
	PrintText(String, -1, FColor::Yellow);
}

void UDeBugz::PrintText(FString String, float Time)
{
	PrintText(String, Time, FColor::Yellow);
}

void UDeBugz::PrintText(FString String, FColor Color)
{
	PrintText(String, -1, Color);
}

void UDeBugz::PrintText(FString String, float Time, FColor Color)
{
#ifdef WITH_EDITOR
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, Time, Color, String);
#endif
}

void UDeBugz::DrawLine(const UWorld* World, FVector Start, FVector End)
{
	DrawLine(World, Start, End, FColor::Cyan);
}

void UDeBugz::DrawLine(const UWorld* World, FVector Start, FVector End, FColor Color)
{
#ifdef WITH_EDITOR
	DrawDebugDirectionalArrow( World, Start, End, 3, Color, false,-1.0f, 0, LineThickness);
#endif
}

void UDeBugz::DrawSphere(const UWorld* World, FVector Center, float Radius, FColor Color)
{
#ifdef WITH_EDITOR
	DrawDebugSphere(World, Center , Radius, 8, Color, false, 2.0f);
#endif
}

