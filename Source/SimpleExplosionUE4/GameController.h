// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuickDebugger.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameController.generated.h"

UCLASS()
class SIMPLEEXPLOSIONUE4_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGameController();

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

	UFUNCTION(BlueprintCallable)
		void SpawnEnemy(TSubclassOf<AActor> _enemy);

	UFUNCTION(BlueprintCallable)
		void ExplodeAllEnemiesIfHeroIsClicked();

	
private:
	QuickDebugger Debug;
	APlayerController* PlayerController;

	
};
