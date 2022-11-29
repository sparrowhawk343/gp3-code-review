// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionSystem/BreakableComponent.h"
#include "Components/HealthComponent.h"
#include "CustomUtility/DeBugz.h"

// Sets default values for this component's properties
UBreakableComponent::UBreakableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBreakableComponent::BeginPlay()
{
	Super::BeginPlay();
	HealthComponent = GetOwner()->FindComponentByClass<UHealthComponent>();
}

void UBreakableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UBreakableComponent::BreakObject(int damageValue)
{
	//if (HealthComponent && HealthComponent->IsAlive)
	//{
	//	//take the damage
	//	HealthComponent->TakeDamage(damageValue);
	//	BreakingObjectDelegate.Broadcast();
	//}
}

void UBreakableComponent::SetField()
{
	SetFieldDelegate.Broadcast();
}


