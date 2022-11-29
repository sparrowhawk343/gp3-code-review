// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BreakableComponent.generated.h"

class AFieldSystemActor;
class UGeometryCollectionComponent;
class UHealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBreakingObjectDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetFieldDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM05_API UBreakableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBreakableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FBreakingObjectDelegate BreakingObjectDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FSetFieldDelegate SetFieldDelegate;

	UFUNCTION(BlueprintCallable, Category = "CustomBreakable")
	void BreakObject(int damageValue);

	UFUNCTION(BlueprintCallable, Category = "CustomBreakable")
	void SetField();

	UPROPERTY()
	UHealthComponent* HealthComponent;
};
