// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/*This class controls the basics of the game. It has:
 *  - A reference to an Actor class in order to choose which actor will be spawned.
 *  - A list of enemy actors already spawned.
 *  - A hero who will be clicked in order to explode the enemies.
 */

 //It's important to remember that in c++ some headers must be added in order for the code to work.
 //But they can not be added after GameController.generated.h

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuickDebugger.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameController.generated.h"

UCLASS()
class SIMPLEEXPLOSIONUE4_API AGameController : public AActor
{
	//Generated body sometimes gets a red underline. Deleting spaces after public: and such should do it.
	//CTRL X and CTRL V can do it too after saving and compiling.
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameController();

	//When spawning an actor, one cannot reference and AActor directly, instead, a TSubclassOf<class> must be used.

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor> EnemyToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> AllTheEnemiesActors;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AHero* hero;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFunctions that are blueprint callable must be set to public.
	UFUNCTION(BlueprintCallable)
		void SpawnEnemy(TSubclassOf<AActor> _enemy);

	UFUNCTION(BlueprintCallable)
		void ExplodeAllEnemiesIfHeroIsClicked();

	UFUNCTION(BlueprintCallable)
		void CheckIfEnemiesMustBeDeleted();


private:
	QuickDebugger Debug;
	APlayerController* PlayerController;


};
