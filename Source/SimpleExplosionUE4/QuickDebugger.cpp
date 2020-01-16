// Fill out your copyright notice in the Description page of Project Settings.


#include "QuickDebugger.h"
#include "Containers/UnrealString.h"

QuickDebugger::QuickDebugger()
{
}

QuickDebugger::~QuickDebugger()
{
}

void QuickDebugger::Log(FString message)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *message));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *message);
}
