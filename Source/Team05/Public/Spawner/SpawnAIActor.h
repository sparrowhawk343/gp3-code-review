// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnAIActor.generated.h"

UCLASS()
class TEAM05_API ASpawnAIActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnAIActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ActorToSpawn;
	
	UFUNCTION()
	void SpawningAI();
	
	UFUNCTION()
	void SpawningDeferredAI();

public:
	UPROPERTY(EditAnywhere)
    bool bStopSpawning = false;
	
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnObject();

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnObjectDeferred();
};
