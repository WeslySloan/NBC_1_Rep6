// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class NBC_1_REP6_API APlatformSpawner : public AActor
{
    GENERATED_BODY()

public:
    APlatformSpawner();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    TSubclassOf<AActor> RotatingPlatformClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    TSubclassOf<AActor> MovingPlatformClass;

    // 스폰 개수
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings", meta = (ClampMin = "0"))
    int32 NumToSpawn;

    // 스폰 범위 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    FVector SpawnBoxExtent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    FVector2D RotationSpeedRange; // x=min, y=max 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    FVector2D MoveSpeedRange; // x=min, y=max

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Settings")
    FVector2D MaxRangeRange; // x=min, y=max 

    void SpawnRandomPlatforms();
};
