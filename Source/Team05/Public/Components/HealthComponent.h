// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Widget/FloatingDamage.h"
#include "HealthComponent.generated.h"

UCLASS( Blueprintable )
class TEAM05_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void DestroyFloaters();

	UFUNCTION(BlueprintCallable)
	void SpawnFloatingText();

	UPROPERTY(EditAnywhere, Category = "CustomBreakable", BlueprintReadWrite)
	int Health = 2;

	UPROPERTY(EditAnywhere, Category = "CustomBreakable", BlueprintReadWrite)
	int Damage = 1;

	UPROPERTY(EditAnywhere, Category = "CustomBreakable", BlueprintReadWrite)
	TSubclassOf<AFloatingDamage> FloatingTextClass;

	UPROPERTY(EditAnywhere, Category = "CustomBreakable", BlueprintReadWrite)
	TArray<AFloatingDamage*> FloatingTexts;
	
	UPROPERTY(BlueprintReadWrite, Category = "CustomBreakable")
	bool IsAlive = true;

	UFUNCTION(BlueprintCallable, Category = "CustomBreakable")
	bool TakeDamage(int value, AActor* FromActor);

	UFUNCTION(BlueprintCallable, Category = "CustomBreakable")
	bool DealDamage(UHealthComponent* HealthComponent ,int value);
	
	UFUNCTION(BlueprintCallable, Category = "CustomBreakable")
	bool Heal(int value);

	UPROPERTY(BlueprintReadOnly)
	int CurrentHealth = 0;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageTaken(AActor* FromActor);
	
};


