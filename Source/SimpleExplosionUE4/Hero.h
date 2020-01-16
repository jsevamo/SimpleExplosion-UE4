// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuickDebugger.h"
#include "Hero.generated.h"

UCLASS()
class SIMPLEEXPLOSIONUE4_API AHero : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHero();

	UPROPERTY(EditAnywhere)
		bool bIsClicked;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void HasBeenClicked();

	void setIsClicked(bool set);
	bool getIsClicked();

private:
	QuickDebugger Debug;

};
