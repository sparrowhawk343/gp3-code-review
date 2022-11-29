// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TimerComponent.h"
#include "CustomUtility/DeBugz.h"



// Sets default values for this component's properties
UTimerComponent::UTimerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();
	LoopingAssetOn();
	Time = TimerData->CurrentTimer;
	if (Time > FirstDelay)
	{
		TimerData->CurrentTimer = FirstDelay;
	}
	
	GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle, this, &UTimerComponent::TimerFunction, InRate, Loops, FirstDelay);
}

void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (TimerData->bTimerCounting)
	{
		if(Time > 0.f)
		{
			Time -= DeltaTime;
			TimerData->CurrentTimer = Time;
		}
		else
		{
			Time = 0.f;
			LoopingAssetOff();
			TimerData->CurrentTimer = Time;
		}
	}
	
}

void UTimerComponent::SetAssetToHighNumer()
{
	TimerData->CurrentTimer = 999.f;
}
void UTimerComponent::LoopingAssetOn()
{
	TimerData->bTimerCounting = true;
}
void UTimerComponent::LoopingAssetOff()
{
	TimerData->bTimerCounting = false;
}

void UTimerComponent::TimerFunction()
{
	for (int i = 0; i < AmontOfSpawnedObjectsPerTick; ++i)
	{
		TimerIsDoneDeligate.Broadcast();
	}
	
	
	CallTracker--;

	CallTracker == 0 ? UDeBugz::PrintText("Finished Looping", 1.f, FColor::Green), GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle) : UDeBugz::PrintText("Timer Called",1.f, FColor::Red);

	UDeBugz::PrintText(FString::Printf(TEXT("Calls Remaining: %d"), CallTracker), 1.f);
}
