// Fill out your copyright notice in the Description page of Project Settings.


#include "GameController.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;
	
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ExplodeAllEnemiesIfHeroIsClicked();

}

void AGameController::SpawnEnemy(TSubclassOf<AActor> _enemy)
{
	FActorSpawnParameters Spawn;
	FVector spawnPos(FMath::RandRange(-400, 400), FMath::RandRange(-400, 400), 200);
	FRotator spawnRot(0, 0, 0);

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(_enemy, spawnPos, spawnRot, Spawn);


	Debug.Log(SpawnedActor->GetName());

	AllTheEnemiesActors.Add(SpawnedActor);

}

void AGameController::ExplodeAllEnemiesIfHeroIsClicked()
{
	if (hero->bIsClicked)
	{


		for (int32 i = 0; i < AllTheEnemiesActors.Num(); i++)
		{
			AActor* a = AllTheEnemiesActors[i];
			AEnemy* b = Cast<AEnemy>(a);
			b->Explode();
		}



		hero->setIsClicked(false);
	}
}

