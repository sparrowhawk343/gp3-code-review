// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_AbilityComponent.generated.h"

class UBreakableComponent;
class UInteractComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM05_API UAC_AbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_AbilityComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Victors bool
	UPROPERTY(BlueprintReadWrite)
	bool SweepConnected = false;
	UPROPERTY(BlueprintReadWrite)
	bool IsDoingAbility = false;
	
	//Dash
	UPROPERTY(EditDefaultsOnly, Category="Dash")
	bool HasDashAbility = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool CanDash = true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Dash")
	float DashLength = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dash")
	float DashCooldown = 2.0f;
	
	UPROPERTY(EditAnywhere, Category="Animation")
	UAnimMontage* DashMontage;

	//Punch
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	TArray<TEnumAsByte<EObjectTypeQuery>> PunchTraceObjectTypes;
	
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	bool HasPunchAbility = true;
	UPROPERTY(BlueprintReadWrite)
	bool CanPunch = true;
	
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	int PunchStrength = 1;
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	float PunchDuration = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	float PunchRange = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category="Punch")
	float PunchRadius = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Punch")
	float PunchCooldown = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Punch")
	float PunchForwardStepDistance = 100.0f;

	
	// UPROPERTY(EditAnywhere, Category="Animation")
	// UAnimMontage* PunchMontage;
	
	//Lunge
	UPROPERTY(BlueprintReadWrite, Category="Lunge")
	bool CanLunge = true;

	UPROPERTY(EditDefaultsOnly, Category="Lunge")
	bool HasLungeAbility = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lunge")
	float LungeRange = 5000.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lunge")
	float LungeCooldown = 6.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lunge")
	float ShortLungeCooldown = 1.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lunge")
	float LungeRadius = 200.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lunge")
	int LungeDamage = 4;
	
	//Pickup
	UPROPERTY(EditDefaultsOnly, Category="Pickup/Throw")
	float PickupRange = 100.0f;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	
	UFUNCTION(BlueprintCallable)
	bool TryDash();
	void ProcessHitObject(AActor* OtherActor, int Damage);
	UFUNCTION(BlueprintCallable)
	bool TryPunch();
	UFUNCTION(BlueprintCallable)
	void PunchAttack(FVector StartLocation);
	
	UFUNCTION(BlueprintCallable)
	bool TryLungeMovement();
	UFUNCTION(BlueprintCallable)
	void LungeAttack(TArray<AActor*> Actors); 

	UFUNCTION()
	bool TryTrace(FHitResult& Hit, int RayLength);
	UFUNCTION()
	bool TrySweep(FHitResult& Hit, int RayLength, float Radius, FVector StartLocation);
	UFUNCTION()
	bool TrySweepMulti(TArray<FHitResult> &Hits, int RayLength, float Radius, FVector StartLocation);
	
};
