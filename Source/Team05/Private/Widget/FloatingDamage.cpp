// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/FloatingDamage.h"

// Sets default values
AFloatingDamage::AFloatingDamage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingDamage::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingDamage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FString AFloatingDamage::GetRandomText(bool Protection)
{
	TArray<FString> Texts;
	if(Protection)
	{
		const TArray<FString> Temp = { "POW!", "CRASH!", "YIKES!", "OOF!", "BANG!", "BOOM!", "BAM!", "X?#H@!", "F@!!#", "SHOOT!",
		"FLOOP!", "FLIP?!"};
		Texts.Append(Temp);
	}
	else
	{
		const TArray<FString> Temp = { "FUCK!", "DAMN!", "SHIT!", "KURWA!", "HELL!", "BOLLOCKS!", "FRIGGER!", "X?#H@!", "F@!!#", "EFFING!",
		"PISS!", "BITCH?!", "ARSE", "ASS", "CRAP", "CUNT", "TWAT!", "BUGGER!", "DAVE"};
		Texts.Append(Temp);
	}
	int num = FMath::RandRange(0, Texts.Num() - 1);
	return Texts[num];
}

