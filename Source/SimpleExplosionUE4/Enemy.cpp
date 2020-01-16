// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Materials/Material.h"
#include <string>

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//staticMeshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>(); There is no owner this time.


	staticMeshComponent = FindComponentByClass<UStaticMeshComponent>();

	ChangeMaterialColor();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckIfTooLow();
}

void AEnemy::Explode()
{
	staticMeshComponent->AddRadialImpulse(FVector(0, 0, 0), 100000, 150000, RIF_Constant, false);
	Debug.Log("exploded");
}

AEnemy* AEnemy::ReturnSelf()
{
	return this;
}


void AEnemy::CheckIfTooLow()
{
	if (staticMeshComponent->GetComponentLocation().Z < -5000)
	{
		staticMeshComponent->SetWorldLocation(FVector(FMath::RandRange(-400, 400), FMath::RandRange(-400, 400), 2000));
	}
}

void AEnemy::ChangeMaterialColor()
{
	auto Mat = staticMeshComponent->GetMaterial(0);

	DynamicMat = UMaterialInstanceDynamic::Create(Mat, this);

	staticMeshComponent->SetMaterial(0, DynamicMat);

	DynamicMat->SetVectorParameterValue(TEXT("Color"), FLinearColor::MakeRandomColor());
}

