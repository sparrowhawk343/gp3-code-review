// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AC_AbilityComponent.h"

#include <string>

#include "GameFramework/Character.h"
#include "InteractionSystem/BreakableComponent.h"
#include "CustomUtility/DeBugz.h"
#include "DrawDebugHelpers.h"
#include "Components/HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InteractionSystem/InteractComponent.h"


// Sets default values for this component's properties
UAC_AbilityComponent::UAC_AbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_AbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}

bool UAC_AbilityComponent::TryDash()
{
	if (!CanDash || IsDoingAbility)
	{
		return false;
	}
	
	CanDash = false;
	IsDoingAbility = true;
	
	return true;
}

void UAC_AbilityComponent::ProcessHitObject(AActor* OtherActor, int Damage) //Take in amount of damage
{
	if (OtherActor)
	{
		UHealthComponent* OtherHealthComponent = OtherActor->FindComponentByClass<UHealthComponent>();
		if (OtherHealthComponent) 
		{
			OtherHealthComponent->TakeDamage(Damage, GetOwner());
		}
	}
}

bool UAC_AbilityComponent::TryPunch()
{
	if (!CanPunch || IsDoingAbility)
	{
		return false;
	}
	
	IsDoingAbility = true;
	CanPunch = false;
	return true;
	//Player cannot rotate/move while punching (have a small pause of input while punching)
}

void UAC_AbilityComponent::PunchAttack(FVector StartLocation)
{
	TArray<FHitResult> Hits;
	bool hit = TrySweepMulti(Hits, PunchRange, PunchRadius, StartLocation);
	if (hit)
	{
		for (auto& Hit : Hits)
		{
			ProcessHitObject(Hit.GetActor(), PunchStrength);
		}
	}

	//GetWorld()->FlushLevelStreaming();
}

bool UAC_AbilityComponent::TryLungeMovement()
{
	if (!CanLunge || IsDoingAbility)
	{
		return false;
	}

	//Dashing 
	IsDoingAbility = true;
	CanLunge = false;
	return true;
	//Todo: Set Player state "Lunge/isLunging" (animation)
}

void UAC_AbilityComponent::LungeAttack(TArray<AActor*> Actors)
{
	if(Actors.Num() == 0)
	{
		return;
	}
	
	TArray<UHealthComponent*> HealthComponents;
	for (AActor* Actor : Actors)
	{
		UHealthComponent* HealthComponent = Actor->FindComponentByClass<UHealthComponent>();
		if (HealthComponent)
		{
			HealthComponents.Add(HealthComponent);
		}
	}
	
	if (HealthComponents.Num() == 0)
	{
		return;
	}

	for (auto HealthComponent : HealthComponents)
	{
		ProcessHitObject(HealthComponent->GetOwner(), LungeDamage);
	}
}

// This function raycasts and returns if an object was hit by the ray
bool UAC_AbilityComponent::TryTrace(FHitResult& Hit, int RayLength)
{
	FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();
	FVector Start = Location;
	FVector End = Location + GetOwner()->GetActorForwardVector() * RayLength + Rotation.Vector();
	
	bool Trace = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility);
	if(Trace)
	{
		UDeBugz::DrawLine(GetWorld(), Start, End, FColor::Green);
	}
	else
	{
		UDeBugz::DrawLine(GetWorld(), Start, End, FColor::Red);
	}
	return Trace;
}

bool UAC_AbilityComponent::TrySweep(FHitResult& Hit, int RayLength, float Radius, FVector StartLocation)
{
	// FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();
	FVector Start = StartLocation;
	FVector End = StartLocation + GetOwner()->GetActorForwardVector() * RayLength + Rotation.Vector();

	FCollisionShape HitBoxCollisionShape = FCollisionShape::MakeSphere(Radius);
	
	bool Trace = GetWorld()->SweepSingleByObjectType(Hit, Start, End, FQuat::Identity, PunchTraceObjectTypes, HitBoxCollisionShape);
	
	if(Trace)
	{
		//TODO: To be removed
		SweepConnected = true;
	}

	return Trace;
}

bool UAC_AbilityComponent::TrySweepMulti(TArray<FHitResult> &Hits, int RayLength, float Radius, FVector StartLocation)
{
	FRotator Rotation = GetOwner()->GetActorRotation();
	FVector Start = StartLocation;
	FVector End = StartLocation + GetOwner()->GetActorForwardVector() * RayLength + Rotation.Vector();
	FCollisionShape HitBoxCollisionShape = FCollisionShape::MakeSphere(Radius);
	
	bool Trace = GetWorld()->SweepMultiByObjectType(Hits, Start, End, FQuat::Identity, PunchTraceObjectTypes, HitBoxCollisionShape);
	if(Trace)
	{
		//TODO: To be removed
		SweepConnected = true;
	}
	return Trace;
}

// Called every frame
void UAC_AbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

