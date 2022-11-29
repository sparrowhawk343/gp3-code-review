// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ChaosCounter.h"
#include "CustomUtility/DeBugz.h"

// Sets default values for this component's properties
UChaosCounter::UChaosCounter()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UChaosCounter::BeginPlay()
{
	Super::BeginPlay();
	
	if (ChaosAsset)
	{
		ChaosAsset->Register(ObjectValue);
	}
}

void UChaosCounter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


