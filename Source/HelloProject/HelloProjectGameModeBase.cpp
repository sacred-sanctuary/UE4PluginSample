// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "HelloProjectGameModeBase.h"
#include "HelloWorldPlugin.h"

void AHelloProjectGameModeBase::BeginPlay() {
	Super::BeginPlay();

#if PLATFORM_ANDROID
	FHelloWorldPluginModule& module = FHelloWorldPluginModule::Get();
#endif //PLATFORM
}
