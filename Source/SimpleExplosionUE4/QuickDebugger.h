// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

/**
 * 
 */
class SIMPLEEXPLOSIONUE4_API QuickDebugger
{
public:
	QuickDebugger();
	~QuickDebugger();

	void Log(FString message);
};
