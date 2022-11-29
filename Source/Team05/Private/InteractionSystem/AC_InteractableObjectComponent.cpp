// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionSystem/AC_InteractableObjectComponent.h"

// Sets default values for this component's properties
UAC_InteractableObjectComponent::UAC_InteractableObjectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//Make sure we set the correct object type
//OnInteract function


// Called when the game starts
void UAC_InteractableObjectComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UAC_InteractableObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

