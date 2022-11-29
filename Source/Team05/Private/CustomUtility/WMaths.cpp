// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomUtility/WMaths.h"

FRotator UWMaths::Rotation8Ways(float Right, float Forward, FVector LastRotationVector, FVector & OutLastRotationVector)
{
	FVector RotationVector = FVector(Forward, Right, 0.f);
	if (Right == 0 && Forward == 0)
	{
		return LastRotationVector.ToOrientationRotator();
	}
	RotationVector.Normalize();
	OutLastRotationVector = RotationVector;
	return RotationVector.ToOrientationRotator();
}

FVector UWMaths::EmtyTestThing(FVector Vector, FRotator Rotator, bool bYesNo, int iInteger, FString sText)
{
	return FVector();
}


