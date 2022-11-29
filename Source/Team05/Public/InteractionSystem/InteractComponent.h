// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SC_PlayerHandPosition.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAM05_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	bool InteractPressed = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Sphere Overlap
	UFUNCTION()
	TArray<AActor*> SphereCast();
	
	UFUNCTION()
	AActor* GetBestInteractable(TArray<AActor*> InRangeArray);
	
	UPROPERTY(BlueprintReadOnly, Category="Pickup") //For debug purpose
	AActor* NearestInteractable;
	
	UPROPERTY(EditAnywhere, Category="Pickup")
	TArray<TEnumAsByte<EObjectTypeQuery>> HitObjectTypes;

	UPROPERTY(EditAnywhere, Category="Pickup")
	float SphereCastRadius = 250.0f;
	UPROPERTY(EditAnywhere, Category="Pickup")
	float InteractDotThreshold = 0.85;
	
	//Pickup
	UFUNCTION(BlueprintCallable)
	void PickUpActor(AActor* ActorToPickup);

	UFUNCTION(BlueprintCallable)
	void SetFieldDynamic(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void TryInteract();

	UPROPERTY()
	USC_PlayerHandPosition* HandPosition;
	
	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	float PickupRange;

	UPROPERTY(BlueprintReadWrite)
	bool HoldingObject = false;
	
	UPROPERTY(BlueprintReadOnly, Category="Pickup")
	AActor* ActorInHand;
	//Drop
	UFUNCTION(BlueprintCallable)
	void Drop();

	//Throw
	UFUNCTION(BlueprintCallable)
	bool TryThrow();
	UFUNCTION(BlueprintCallable)
	void DoThrow();
	
	UPROPERTY(EditAnywhere, Category="Throw")
	float ThrowForce = 10.0f;

	//Input
	UFUNCTION(BlueprintCallable)
	void InteractActionPressed();
	UFUNCTION(BlueprintCallable)
	void InteractActionReleased();
	UFUNCTION(BlueprintCallable)
	void ThrowActionPressed();
};
