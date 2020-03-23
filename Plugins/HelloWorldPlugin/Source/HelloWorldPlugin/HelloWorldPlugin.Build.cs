// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class HelloWorldPlugin : ModuleRules
{
	public HelloWorldPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		PublicIncludePathModuleNames.AddRange(
			new string[]
			{
				"Launch",
			}
			);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		// 
		LoadThardParty(Target);
	}

	public void LoadThardParty(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.Win64) {
			// Plugin settings for Windows
		} else if ((Target.Platform == UnrealTargetPlatform.IOS) || (Target.Platform == UnrealTargetPlatform.Mac)) {
			// Plugin settings for iOS
		} else if (Target.Platform == UnrealTargetPlatform.Android) {
			// Plugin settings for Android
			PrivateIncludePaths.AddRange(
				new string[] {
					"HelloWorldPlugin/Private/Android",
				});
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AndroidHelloWorldPlugin_UPL.xml"));
		}
	}
}
