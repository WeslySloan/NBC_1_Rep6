// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class NBC_1_REP6_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // �̵� �ӵ� 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings", meta = (ClampMin = "0.0"))
    float MoveSpeed;

    // ���� ��ġ�κ��� �ִ� �Ÿ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings", meta = (ClampMin = "0.0"))
    float MaxRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector MoveAxis;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform Settings")
    FVector StartLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    bool bUseLocalSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    bool bStartMovingForward;

private:
    bool bMovingForward;
};
