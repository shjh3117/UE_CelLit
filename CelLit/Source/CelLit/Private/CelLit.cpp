// Copyright Epic Games, Inc. All Rights Reserved.

#include "CelLit.h"
#include "HAL/PlatformFilemanager.h"

#define LOCTEXT_NAMESPACE "FCelLitModule"

void FCelLitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

    const FString EngineShaderDir = FPaths::Combine(FPaths::EngineDir(), TEXT("/Shaders/Private"));
    const FString CustomShaderDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("/CelLit/Shaders/Private"));
    const FString BackupDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("/CelLit/Shaders/Temp"));

    PlatformFile.CopyDirectoryTree(*BackupDir, *EngineShaderDir, true);
    PlatformFile.CopyDirectoryTree(*EngineShaderDir, *CustomShaderDir, true);
}

void FCelLitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

    const FString EngineShaderDir = FPaths::Combine(FPaths::EngineDir(), TEXT("/Shaders/Private"));
    const FString CustomShaderDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("/CelLit/Shaders/Private"));
    const FString BackupDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("/CelLit/Shaders/Temp"));

    // PlatformFile.DeleteDirectoryRecursively(*EngineShaderDir);
    PlatformFile.CopyDirectoryTree(*EngineShaderDir, *BackupDir, true);
    PlatformFile.DeleteDirectoryRecursively(*BackupDir);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCelLitModule, CelLit)