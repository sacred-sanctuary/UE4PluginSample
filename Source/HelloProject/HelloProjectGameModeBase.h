// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HelloProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HELLOPROJECT_API AHelloProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
};
