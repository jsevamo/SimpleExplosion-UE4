// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "QuickDebugger.h"
#include "Hero.h"
#include "Enemy.generated.h"

UCLASS()
class SIMPLEEXPLOSIONUE4_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* staticMeshComponent;

	//A dynamic instance of a material must be created in order to change the color of the material in real time.
	UMaterialInstanceDynamic* DynamicMat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasBeenClicked;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Add a radial impulse to each enemy so it explodes.
	UFUNCTION(BlueprintCallable)
		void Explode(FVector heroPos);

	AEnemy* ReturnSelf();

	UFUNCTION(BlueprintCallable)
		void CheckIfTooLow();

	UFUNCTION(BlueprintCallable)
		void ChangeMaterialColor();

	UFUNCTION(BlueprintCallable)
		void DeleteEnemy();

private:
	QuickDebugger Debug;


};
