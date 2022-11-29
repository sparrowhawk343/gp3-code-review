// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionSystem/SC_PlayerHandPosition.h"

// Sets default values for this component's properties
USC_PlayerHandPosition::USC_PlayerHandPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USC_PlayerHandPosition::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USC_PlayerHandPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

