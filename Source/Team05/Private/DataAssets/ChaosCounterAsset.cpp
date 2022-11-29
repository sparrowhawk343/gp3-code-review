// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/ChaosCounterAsset.h"

void UChaosCounterAsset::Register(int value)
{
	CounterMaxValue += value;
}

void UChaosCounterAsset::Deregister(int value)
{
	CounterCurrent += value;
}

void UChaosCounterAsset::ResetObj()
{
	CounterCurrent = 0;
	CounterMaxValue = 0;
}

float UChaosCounterAsset::GetPercent()
{
	float count = PercentageFull / 100 * CounterMaxValue / 100;
	float value = CounterCurrent / count;
	return value / 100;
}
