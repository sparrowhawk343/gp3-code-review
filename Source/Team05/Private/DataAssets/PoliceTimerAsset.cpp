// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/PoliceTimerAsset.h"


void UPoliceTimerAsset::ResetObj()
{
	CurrentTimer = 0.f;
}


void UPoliceTimerAsset::SetObj999()
{
	CurrentTimer = 999.f;
}
