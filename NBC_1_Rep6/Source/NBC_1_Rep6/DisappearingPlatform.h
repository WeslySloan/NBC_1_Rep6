// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisappearingPlatform.generated.h"

UCLASS()
class NBC_1_REP6_API ADisappearingPlatform : public AActor
{
    GENERATED_BODY()

public:
    ADisappearingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // 보이는 시간 (초)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer Settings", meta = (ClampMin = "0.0"))
    float VisibleTime;

    // 사라진 상태 유지 시간 (초)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer Settings", meta = (ClampMin = "0.0"))
    float InvisibleTime;

    // 처음 시작할 때 보이는 상태인지
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer Settings")
    bool bStartVisible;

protected:
    FTimerHandle ToggleTimerHandle;
    bool bIsVisible;

    void ToggleVisibility();
    void SetPlatformVisible(bool bVisible);
};