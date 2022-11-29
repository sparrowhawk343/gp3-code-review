// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/SpawnAIActor.h"

// Sets default values
ASpawnAIActor::ASpawnAIActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnAIActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnAIActor::SpawnObject()
{
	if (bStopSpawning)
	{
		return;
	}
	SpawningAI();
}

void ASpawnAIActor::SpawnObjectDeferred()
{
	if (bStopSpawning)
	{
		return;
	}
	SpawnObjectDeferred();
}


void ASpawnAIActor::SpawningAI() 
{
	FTransform Transform = GetActorTransform();
	if (ActorToSpawn)
	{
		GetWorld()->SpawnActor<AActor>(ActorToSpawn, Transform);
	}
}

void ASpawnAIActor::SpawningDeferredAI()
{
	FTransform Transform = GetActorTransform();
	if (ActorToSpawn)
	{
		GetWorld()->SpawnActorDeferred<AActor>(ActorToSpawn, Transform);
	}
}


