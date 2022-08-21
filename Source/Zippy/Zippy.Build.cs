// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Zippy : ModuleRules
{
	public Zippy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
