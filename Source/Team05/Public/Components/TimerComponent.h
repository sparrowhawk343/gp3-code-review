// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DataAssets/PoliceTimerAsset.h"
#include "TimerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTimerIsDoneDeligate);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM05_API UTimerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimerComponent();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	float Time;
	
public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "TimerComponent")
	void SetAssetToHighNumer();
	UFUNCTION(BlueprintCallable, Category = "TimerComponent")
	void LoopingAssetOn();
	UFUNCTION(BlueprintCallable, Category = "TimerComponent")
	void LoopingAssetOff();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FTimerIsDoneDeligate TimerIsDoneDeligate;
	
	UPROPERTY(EditAnywhere)
	int CallTracker = 3;

	UPROPERTY(EditAnywhere)
	float InRate = 3.0f;
	UPROPERTY(EditAnywhere)
	bool Loops = true;
	UPROPERTY(EditAnywhere)
	float FirstDelay = 0.5f;

	UPROPERTY(EditAnywhere)
	int AmontOfSpawnedObjectsPerTick = 1;

	UFUNCTION(BlueprintCallable, Category = "TimerComponent")
	void TimerFunction();
	
	UPROPERTY(Category = "TimerComponent", EditAnywhere, BlueprintReadWrite)
	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPoliceTimerAsset* TimerData;
	
};
