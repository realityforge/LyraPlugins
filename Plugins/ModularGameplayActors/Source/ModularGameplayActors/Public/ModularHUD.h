// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/HUD.h"

#include "ModularHUD.generated.h"

#define UE_API MODULARGAMEPLAYACTORS_API

namespace EEndPlayReason { enum Type : int; }

/** Minimal class that supports extension by game feature plugins */
UCLASS(Abstract, MinimalAPI, Blueprintable)
class AModularHUD : public AHUD
{
    GENERATED_BODY()

protected:
    //~UObject interface
    UE_API virtual void PreInitializeComponents() override;
    //~End of UObject interface

    //~AActor interface
    UE_API virtual void BeginPlay() override;
    UE_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    //~End of AActor interface
};

#undef UE_API
