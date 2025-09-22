// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    // ±âº» °ª
    RotationSpeed = 90.f;
    RotationAxis = FVector::UpVector; 
    bRotateLocal = true;
}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (RotationAxis.IsNearlyZero() || FMath::IsNearlyZero(RotationSpeed))
    {
        return;
    }

    FVector Axis = RotationAxis.GetSafeNormal();
    const float AngleRad = FMath::DegreesToRadians(RotationSpeed * DeltaTime);
    const FQuat DeltaQuat(Axis, AngleRad);

    if (bRotateLocal)
    {
        AddActorLocalRotation(FRotator(DeltaQuat));
    }
    else
    {
        AddActorWorldRotation(FRotator(DeltaQuat));
    }
}

