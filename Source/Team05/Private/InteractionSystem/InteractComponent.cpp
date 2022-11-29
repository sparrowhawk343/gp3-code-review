// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionSystem/InteractComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Vector.h"
#include "InteractionSystem/AC_InteractableObjectComponent.h"
#include "CustomUtility/DeBugz.h"
#include "Components/PrimitiveComponent.h"
#include "InteractionSystem/AC_Pickup.h"
#include "InteractionSystem/BreakableComponent.h"
#include "PhysicsField/PhysicsFieldComponent.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	HandPosition = GetOwner()->FindComponentByClass<USC_PlayerHandPosition>();
}

// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInteractComponent::TryInteract()
{
	UAC_InteractableObjectComponent* InteractComponent = NearestInteractable->FindComponentByClass<UAC_InteractableObjectComponent>();
	if (InteractComponent)
	{
		InteractComponent->OnInteract(GetOwner());
	}
}

void UInteractComponent::PickUpActor(AActor* ActorToPickup)
{
	if(!HandPosition)
	{
		return;
	}
	//Drop if already holding
	if (ActorInHand)
	{
		return;
	}

	//Todo: Turn of physics for object while holding
	
	//Pickup
	//TODO: Add socket thingies
	ActorInHand = ActorToPickup;
	ActorInHand->DisableComponentsSimulatePhysics();
	
	UPrimitiveComponent* ActorPrimitiveRoot = Cast<UPrimitiveComponent, USceneComponent>(ActorInHand->GetRootComponent());
	// ActorPrimitiveRoot->SetCollisionResponseToChannel(ECC_GameTraceChannel14, ECollisionResponse::ECR_Ignore);
	
	ActorInHand->SetActorEnableCollision(false);
	
	ActorPrimitiveRoot->SetSimulatePhysics(false);
	
	ActorPrimitiveRoot->PutAllRigidBodiesToSleep();
	
	ActorInHand->AttachToComponent(HandPosition,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	HoldingObject = true;
	ActorToPickup = nullptr;
}

void UInteractComponent::SetFieldDynamic(AActor* OtherActor)
{
	UBreakableComponent* BreakableComponent = OtherActor->FindComponentByClass<UBreakableComponent>();
	if (BreakableComponent)
	{
		UDeBugz::PrintText("DROP");
		BreakableComponent->SetField();
	}
}

void UInteractComponent::Drop()
{
	if (!ActorInHand)
	{
		return;
	}
	
	//Drop from hand
	ActorInHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ActorInHand->SetActorEnableCollision(true);
	ActorInHand->SetActorRotation(FRotator::ZeroRotator);
	
	UPrimitiveComponent* ActorPrimitiveRoot = Cast<UPrimitiveComponent, USceneComponent>(ActorInHand->GetRootComponent());
	if (ActorPrimitiveRoot)
	{
		ActorPrimitiveRoot->SetSimulatePhysics(true);
	}
	//SetFieldDynamic(ActorInHand);
	
	HoldingObject = false;
	ActorInHand = nullptr;
}

bool UInteractComponent::TryThrow()
{
	if (!ActorInHand)
	{
		return false;
	}

	return true;
}

void UInteractComponent::DoThrow()
{
	FVector PlayerForwardVector = GetOwner()->GetActorForwardVector();
	float ObjectForceMultiplier = 1.0f;
	UAC_Pickup* PickupComponent = nullptr;

	if (!ActorInHand)
	{
		return;
	}
	
	PickupComponent = ActorInHand->FindComponentByClass<UAC_Pickup>();
	
	if (!PickupComponent)
	{
		return;
	}
	
	ObjectForceMultiplier = PickupComponent->ThrowForceMultiplier;
	
	ActorInHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ActorInHand->SetActorRotation(FRotator::ZeroRotator);
	ActorInHand->SetActorEnableCollision(true);
	
	UPrimitiveComponent* ActorPrimitiveRoot = Cast<UPrimitiveComponent, USceneComponent>(ActorInHand->GetRootComponent());
	if (ActorPrimitiveRoot)
	{
		//TODO: force mass to get consistent results
		// ActorPrimitiveRoot->SetMassOverrideInKg(NAME_None, 10);
		// ActorPrimitiveRoot->SetCollisionResponseToChannel(ECC_GameTraceChannel14, ECollisionResponse::ECR_Block);
		ActorPrimitiveRoot->SetAngularDamping(180);
		ActorPrimitiveRoot->SetSimulatePhysics(true);
		ActorPrimitiveRoot->WakeAllRigidBodies();
		ActorPrimitiveRoot->SetPhysicsLinearVelocity(PlayerForwardVector * ThrowForce * ObjectForceMultiplier);
		ActorPrimitiveRoot->SetNotifyRigidBodyCollision(true);
		
		PickupComponent->BeingThrown = true;
		
		//ActorPrimitiveRoot->AddImpulse(PlayerForwardVector * ThrowForce * 100);
		HoldingObject = false;
		ActorInHand = nullptr;
		PickupComponent = nullptr;
		UDeBugz::PrintText(FString::Printf(TEXT("isphysics: %d"), ActorPrimitiveRoot->IsSimulatingPhysics()), 5.0f);
			}
}

void UInteractComponent::InteractActionPressed()
{
	if (HoldingObject)
	{
		return;
	}
	//Looking for nearest object
	TArray<AActor*> ActorsInRange = SphereCast();
	NearestInteractable = GetBestInteractable(ActorsInRange);
	
	// InteractPressed = true;
	if (NearestInteractable)
	{
		TryInteract();
	}
	// else if (ActorInHand)
	// {
	// 	Drop();
	// }
}

void UInteractComponent::InteractActionReleased()
{
	// InteractPressed = false;
}

void UInteractComponent::ThrowActionPressed()
{
	// TryThrow();
}

TArray<AActor*> UInteractComponent::SphereCast()
{
	// Sphere's spawn location within the world
	FVector Location = GetOwner()->GetActorLocation();
	// Array of actors that are inside the radius of the sphere
	TArray<AActor*> Candidates;
	// Class that the sphere should hit against and include in the outActors array (Can be null)
	// UClass* SeekClass = UAC_InteractableObjectComponent::StaticClass(); //TODO: Only check for interactable
	UClass* SeekClass = nullptr;
	
	// Ignore any specific actors
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Init(GetOwner(), 1);
	if (ActorInHand)
	{
		IgnoreActors.Add(ActorInHand);
	}
	
	// Set what actors to seek out from it's collision channel
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes = HitObjectTypes;
	
	//TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	//Use to have a visual representation of the SphereOverlapActors
	// DrawDebugSphere(GetWorld(),  GetOwner()->GetActorLocation(), SphereCastRadius, 12, FColor::Red, false, 0);
	
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, SphereCastRadius, TraceObjectTypes, SeekClass,
	                                          IgnoreActors, Candidates);
	TArray<AActor*> OutActors;
	for (auto Actor : Candidates)
	{
		UAC_InteractableObjectComponent* InteractableComponent = Actor->FindComponentByClass<UAC_InteractableObjectComponent>();
		if (!InteractableComponent)
		{
			continue;;
		}

		if (InteractableComponent->CanInteract)
		{
			OutActors.Add(Actor);
		}
	}
	return OutActors;
}

AActor* UInteractComponent::GetBestInteractable(TArray<AActor*> InRangeArray)
{
	FVector PlayerLocation = GetOwner()->GetActorLocation();
	FVector PlayerForwardVector = GetOwner()->GetActorForwardVector();
	
	//Get Actor Dots, add to array
	TArray<float> DotProducts;
	for (auto Actor : InRangeArray)
	{
		FVector DirectionToObject = Actor->GetActorLocation() - PlayerLocation; //TODO: Change variable name
		DirectionToObject.Normalize();
		float ActorDot = FVector::DotProduct(PlayerForwardVector, DirectionToObject);
		DotProducts.Add(ActorDot);
	}
	
	//Get best candidate from array
	float BestCandidateDot;
	int BestCandidateIndex;
	UKismetMathLibrary::MaxOfFloatArray(DotProducts,BestCandidateIndex, BestCandidateDot);

	//Debug Dotproduct
	// UDeBugz::PrintText(FString::SanitizeFloat(BestCandidateDot));
	
	if (BestCandidateDot>InteractDotThreshold)
	{
		return InRangeArray[BestCandidateIndex];
	}
	return nullptr;
}
