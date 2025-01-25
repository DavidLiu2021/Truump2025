// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmallBallSpawner.generated.h"

UCLASS()
class TRUUMP2025_API ASmallBallSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASmallBallSpawner();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner Properties")
	float SpawnRate = 1.0f;

	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner Properties")
	TSubclassOf<class ASmallBallActor> BallClass;

	void SpawnBall();

	FVector GetRandomPosition(bool bSpawnFromCenter);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner Properties")
	AActor* CentralBall;

};
