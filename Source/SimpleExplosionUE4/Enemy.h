// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "QuickDebugger.h"
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

	UMaterialInstanceDynamic* DynamicMat;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Explode();

	AEnemy* ReturnSelf();

	UFUNCTION(BlueprintCallable)
		void CheckIfTooLow();

	UFUNCTION(BlueprintCallable)
		void ChangeMaterialColor();

private:
	QuickDebugger Debug;

};
