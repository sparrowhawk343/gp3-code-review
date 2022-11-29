// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BounceeLib.generated.h"

//Functions transfered from:
//https://github.com/DeadMadman/Bouncee
UCLASS()
class TEAM05_API UBouncee : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float Linear(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeLinear(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InSine(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutSine(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutSine(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeSine(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InQuad(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutQuad(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutQuad(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeQuad(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InCub(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutCub(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutCub(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeCub(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InQuart(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutQuart(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutQuart(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeQuart(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InQuint(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutQuint(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutQuint(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeQuint(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InExpo(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutExpo(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutExpo(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeExpo(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InCircular(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutCircular(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutCircular(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeCircular(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InBounce(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutBounce(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutBounce(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeBounce(float t);
	
	static float InElastic(float t, float amplitude, float period);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InElastic(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutElastic(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutElastic(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeElastic(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InBack(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float OutBack(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float InOutBack(float t);
	UFUNCTION(BlueprintPure, Category = "Bouncee")
	static float SpikeBack(float t);
	
	//Helper functions
	static float Invert(float t);
	static float PingPong(float t, float duration);
	static float EvaluateEase();
};