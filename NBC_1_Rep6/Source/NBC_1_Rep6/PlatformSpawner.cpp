// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "RotatingPlatform.h"
#include "MovingPlatform.h"

APlatformSpawner::APlatformSpawner()
{
    PrimaryActorTick.bCanEverTick = false;

    NumToSpawn = 8;
    SpawnBoxExtent = FVector(1000, 1000, 200);

    RotationSpeedRange = FVector2D(30, 180);
    MoveSpeedRange = FVector2D(100, 400);
    MaxRangeRange = FVector2D(200, 1000);
}

void APlatformSpawner::BeginPlay()
{
    Super::BeginPlay();
    SpawnRandomPlatforms();
}

void APlatformSpawner::SpawnRandomPlatforms()
{
    if (!GetWorld()) return;

    for (int32 i = 0; i < NumToSpawn; ++i)
    {
        // 랜덤 위치 (스폰 박스 내)
        FVector RandOffset = FVector(
            FMath::FRandRange(-SpawnBoxExtent.X, SpawnBoxExtent.X),
            FMath::FRandRange(-SpawnBoxExtent.Y, SpawnBoxExtent.Y),
            FMath::FRandRange(-SpawnBoxExtent.Z, SpawnBoxExtent.Z)
        );
        FVector SpawnLocation = GetActorLocation() + RandOffset;
        FRotator SpawnRot = FRotator::ZeroRotator;

        bool bSpawnRotating = (i % 2 == 0) && RotatingPlatformClass;
        if (bSpawnRotating && RotatingPlatformClass)
        {
            FActorSpawnParameters Params;
            AActor* NewActor = GetWorld()->SpawnActor<AActor>(RotatingPlatformClass, SpawnLocation, SpawnRot, Params);
            if (NewActor)
            {
                ARotatingPlatform* RP = Cast<ARotatingPlatform>(NewActor);
                if (RP)
                {
                    RP->RotationSpeed = FMath::FRandRange(RotationSpeedRange.X, RotationSpeedRange.Y);

                    // 랜덤 축
                    /*FVector Axis = UKismetMathLibrary::RandomUnitVector();
                    RP->RotationAxis = Axis;*/
                    RP->bRotateLocal = (FMath::RandBool());
                }
            }
        }
        else if (MovingPlatformClass)
        {
            FActorSpawnParameters Params;
            AActor* NewActor = GetWorld()->SpawnActor<AActor>(MovingPlatformClass, SpawnLocation, SpawnRot, Params);
            if (NewActor)
            {
                AMovingPlatform* MP = Cast<AMovingPlatform>(NewActor);
                if (MP)
                {
                    MP->MoveSpeed = FMath::FRandRange(MoveSpeedRange.X, MoveSpeedRange.Y);
                    MP->MaxRange = FMath::FRandRange(MaxRangeRange.X, MaxRangeRange.Y);

                    // 랜덤 방향 (XZ 평면 위로만)
                    FVector RandDir = FVector(FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f), 0.f).GetSafeNormal();
                    MP->MoveAxis = RandDir;
                    MP->bUseLocalSpace = false;
                }
            }
        }
    }
}
