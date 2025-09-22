// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    MoveSpeed = 200.f;
    MaxRange = 500.f;
    MoveAxis = FVector(1, 0, 0); // X축 방향
    bUseLocalSpace = true;
    bStartMovingForward = true;
    bMovingForward = bStartMovingForward;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    bMovingForward = bStartMovingForward;

    if (bUseLocalSpace)
    {
        MoveAxis = GetActorForwardVector();
    }
    else
    {
        MoveAxis = MoveAxis.GetSafeNormal();
    }
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (MoveSpeed <= 0.f || MaxRange <= 0.f || MoveAxis.IsNearlyZero()) return;

    FVector AxisNorm = MoveAxis.GetSafeNormal();
    FVector Direction = bMovingForward ? AxisNorm : -AxisNorm;
    FVector DeltaMove = Direction * MoveSpeed * DeltaTime;
    FVector NewLocation = GetActorLocation() + DeltaMove;

    float Traveled = FVector::DotProduct(NewLocation - StartLocation, AxisNorm);

    if (Traveled > MaxRange)
    {
        float Over = Traveled - MaxRange;
        NewLocation -= AxisNorm * Over;
        bMovingForward = false;
    }
    else if (Traveled < 0.f)
    {
        // 시작점 뒤로 넘어간 경우(음수)
        float Over = -Traveled;
        NewLocation += AxisNorm * Over;
        bMovingForward = true;
    }

    SetActorLocation(NewLocation);
}

