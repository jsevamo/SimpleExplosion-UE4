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

	bHasBeenClicked = false;


}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckIfTooLow();
}


void AEnemy::Explode(FVector heroPos)
{
	//The static mesh component handles all the physics. So you just get it and the call the needed function.

	staticMeshComponent->AddRadialImpulse(heroPos, 100000, 150000, RIF_Constant, false);
}

AEnemy* AEnemy::ReturnSelf()
{
	return this;
}


void AEnemy::CheckIfTooLow()
{
	//The static mesh component must also be used to get the location of the object in the world.
	if (staticMeshComponent->GetComponentLocation().Z < -5000)
	{
		staticMeshComponent->SetWorldLocation(FVector(FMath::RandRange(-400, 400), FMath::RandRange(-400, 400), 2000));
	}
}

void AEnemy::ChangeMaterialColor()
{
	//This is how to change the material color. Basically you get the current material, create a new Dynamic Material
	// with the current one, set the new material and then change the color.

	auto Mat = staticMeshComponent->GetMaterial(0);

	DynamicMat = UMaterialInstanceDynamic::Create(Mat, this);

	staticMeshComponent->SetMaterial(0, DynamicMat);

	DynamicMat->SetVectorParameterValue(TEXT("Color"), FLinearColor::MakeRandomColor());
}

void AEnemy::DeleteEnemy()
{
	/*If the enemy has been clicked, sets this variable to true, and we can do stuff with it in the GameController
	 *To delete it.
	 */
	bHasBeenClicked = true;
}

