// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    RotationSpeed = 90.f;
    RotationAxis = FVector::UpVector;
    bRotateLocal = true;
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (RotationAxis.IsNearlyZero() || FMath::IsNearlyZero(RotationSpeed)) return;

    FVector Axis = RotationAxis.GetSafeNormal();
    float AngleRad = FMath::DegreesToRadians(RotationSpeed * DeltaTime);

    // 쿼터니언 생성
    FQuat DeltaQuat(Axis, AngleRad);

    if (bRotateLocal)
    {
        AddActorLocalRotation(DeltaQuat, false, nullptr, ETeleportType::None);
    }
    else
    {
        AddActorWorldRotation(DeltaQuat, false, nullptr, ETeleportType::None);
    }
}


