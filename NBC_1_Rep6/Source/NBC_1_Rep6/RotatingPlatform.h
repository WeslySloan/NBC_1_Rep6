// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class NBC_1_REP6_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings", meta = (ClampMin = "0.0"))
    float RotationSpeed;

    // °¢µµ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector RotationAxis; 


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    bool bRotateLocal;
};
