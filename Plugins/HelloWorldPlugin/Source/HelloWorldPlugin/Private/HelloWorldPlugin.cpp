// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HelloWorldPlugin.h"

#define LOCTEXT_NAMESPACE "FHelloWorldPluginModule"
#if PLATFORM_ANDROID
#include "HelloAndroid.h"
#include "utils/log_main.h"
#define LOG_NDEBUG 0
#define LOG_TAG "HelloWorldPlugin-Native"
#endif //PLATFORM

void FHelloWorldPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if PLATFORM_ANDROID
	ALOGV("FHelloWorldPluginModule::StartupModule() [INF] create HelloAndroid");
	HelloAndroid *pHelloAndroid = HelloAndroid::Create();
	check(pHelloAndroid);
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	check(env);
	jobject gameActivity = FAndroidApplication::GetGameActivityThis();
	pHelloAndroid->setup(env, gameActivity);
	pHelloAndroid->startHelloActivity(env);
#endif //PLATFORM

}

void FHelloWorldPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FHelloWorldPluginModule& FHelloWorldPluginModule::Get()
{
	return FModuleManager::GetModuleChecked<FHelloWorldPluginModule>("HelloWorldPlugin");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHelloWorldPluginModule, HelloWorldPlugin)