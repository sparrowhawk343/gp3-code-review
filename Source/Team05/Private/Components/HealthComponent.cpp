// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = Health;
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (FloatingTexts.Num() != 0)
	{
		DestroyFloaters();
	}
}

void UHealthComponent::DestroyFloaters()
{
	for (auto item : FloatingTexts)
	{
		if (!item)
		{
			return;
		}
		if (!item->IsAlive)
		{
			GetWorld()->DestroyActor(item);
		}
	}
}

void UHealthComponent::SpawnFloatingText()
{
	if (FloatingTextClass)
	{
		FVector Location = GetOwner()->GetActorLocation();
		FRotator Rotation = GetOwner()->GetActorRotation();
		auto that = GetOwner()->GetWorld()->SpawnActor<AFloatingDamage>(FloatingTextClass, Location, Rotation);
		that->SetFloater();
		FloatingTexts.Add(that);
	}
}

bool UHealthComponent::TakeDamage(int value, AActor* FromActor)
{
	OnDamageTaken(FromActor);
	
	if (IsAlive)
	{
		CurrentHealth -= value;
		if(CurrentHealth <= 0)
		{
			IsAlive = false;
			return false;
		}
		return true;
	}
	PrimaryComponentTick.bCanEverTick = false;
	IsAlive = false;
	return false;
}

bool UHealthComponent::DealDamage(UHealthComponent* HealthComponent, int value)
{
	return HealthComponent->TakeDamage(value, HealthComponent->GetOwner());
}

bool UHealthComponent::Heal(int value)
{
	if (IsAlive && CurrentHealth < Health)
	{
		CurrentHealth += value;
		return true;
	}
	return false;
}


