// Fill out your copyright notice in the Description page of Project Settings.


#include "DisappearingPlatform.h"

// Sets default values
ADisappearingPlatform::ADisappearingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    VisibleTime = 2.0f;
    InvisibleTime = 1.0f;
    bStartVisible = true;
    bIsVisible = bStartVisible;
}

void ADisappearingPlatform::BeginPlay()
{
    Super::BeginPlay();

    bIsVisible = bStartVisible;
    SetPlatformVisible(bIsVisible);

    // 타이머 시작
    float FirstDelay = bIsVisible ? VisibleTime : InvisibleTime;
    GetWorld()->GetTimerManager().SetTimer(ToggleTimerHandle, this, &ADisappearingPlatform::ToggleVisibility, FirstDelay, false);
}

void ADisappearingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADisappearingPlatform::ToggleVisibility()
{
    bIsVisible = !bIsVisible;
    SetPlatformVisible(bIsVisible);

    float NextDelay = bIsVisible ? VisibleTime : InvisibleTime;
    GetWorld()->GetTimerManager().SetTimer(ToggleTimerHandle, this, &ADisappearingPlatform::ToggleVisibility, NextDelay, false);
}

void ADisappearingPlatform::SetPlatformVisible(bool bVisible)
{
    PlatformMesh->SetVisibility(bVisible, true);
    PlatformMesh->SetCollisionEnabled(bVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}