// Fill out your copyright notice in the Description page of Project Settings.


//Nothing special in this class.

#include "Hero.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHero::AHero()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsClicked = false;
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
	bIsClicked = false;
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHero::HasBeenClicked()
{
	//Debug.Log("Ok I have been clicked");
	bIsClicked = true;
}

void AHero::setIsClicked(bool set)
{
	bIsClicked = set;
}

bool AHero::getIsClicked()
{
	return bIsClicked;
}

FVector AHero::GetPos()
{
	UStaticMeshComponent * StaticMesh = FindComponentByClass<UStaticMeshComponent>();
	
	return StaticMesh->GetComponentLocation();
	
}

