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

	//These two lines of code are used to get the player controller and the use the player controller to show the mouse cursor
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

	//This is how to spawn an actor in the world. As long as you use TSubclassOf<>, it should work with any class.
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(_enemy, spawnPos, spawnRot, Spawn);


	//The magic happens when you assign the SpawnActor<>() function to a variable. Then it turns from TSubclassOf<AActor>
	//to just AActor, and we can add it to the enemies list.
	AllTheEnemiesActors.Add(SpawnedActor);

}

void AGameController::ExplodeAllEnemiesIfHeroIsClicked()
{
	// Just making sure the hero is clicked and there are enemies in the scene before we explode.

	//By the way, it's inside the Hero blueprint that we activate OnClick, and then we use a blueprint to say: When clicked, call the
	//function "HasBeenCLicked". It's all done in blueprints.
	//
	//To activate click events, A TestGameMode was created, so that we could assign a TestPlayerController, which we can use to
	//enable click events.
	//
	
	if (hero->bIsClicked)
	{
		if(AllTheEnemiesActors.Num()>0)
		{
			for (int32 i = 0; i < AllTheEnemiesActors.Num(); i++)
			{
				/*
				 * Allright so here's the thing here, we have a list of enemy actors in the scene, but if we want to explode them,
				 * we can't use the AActor class on them, we have to use the AEnemy class.
				 * Luckily, AEnemy inherits from AActor, so these particular objects are both of type AActor and AEnemy!.
				 *
				 * We then use a Cast to change the type of the objects in the list from AActor to AEnemy, so that on each of them we
				 * can call Explode(). Cool!
				 */
				AActor* enemyActor = AllTheEnemiesActors[i];
				AEnemy* enemy = Cast<AEnemy>(enemyActor);
				enemy->Explode();
			}
		}

		else
		{
			Debug.Log("You need to add at least one enemy. Do that with P!");
		}

		



		hero->setIsClicked(false);
	}
}

