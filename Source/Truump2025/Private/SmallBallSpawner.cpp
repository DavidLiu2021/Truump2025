// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBallSpawner.h"
#include "SmallBallActor.h"
#include "CardData.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

// Sets default values
ASmallBallSpawner::ASmallBallSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASmallBallSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASmallBallSpawner::SpawnBall, SpawnRate, true);
}

void ASmallBallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASmallBallSpawner::SpawnBall()
{
	if (!BallClass || !CentralBall) return;

	bool bSpawnFromCenter = FMath::RandBool();
	FVector SpawnLocation = GetRandomPosition(bSpawnFromCenter);

	FActorSpawnParameters SpawnParams;
	ASmallBallActor* SpawnedBall = GetWorld()->SpawnActor<ASmallBallActor>(BallClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);

	if (SpawnedBall)
	{
		FVector Direction;
		if (bSpawnFromCenter)
		{
			// Spawn from center, move outward
			Direction = (SpawnLocation - CentralBall->GetActorLocation()).GetSafeNormal();
		}
		else
		{
			// Spawn from outside, move toward center
			Direction = (CentralBall->GetActorLocation() - SpawnLocation).GetSafeNormal();
		}

		SpawnedBall->MoveDirection = Direction;
		SpawnedBall->MoveSpeed = FMath::FRandRange(200.0f, 400.0f); // Random speed
	}
}

FVector ASmallBallSpawner::GetRandomPosition(bool bSpawnFromCenter)
{
	FVector PlaneExtent = FVector(10.0f, 10.0f, -40.0f); // Adjust this based on your map
	FVector SpawnLocation;

	if (bSpawnFromCenter)
	{
		SpawnLocation = CentralBall->GetActorLocation(); // Start at center
	}
	else
	{
		// Random point on the plane's edge
		float X = FMath::FRandRange(-PlaneExtent.X, PlaneExtent.X);
		float Y = FMath::FRandRange(-PlaneExtent.Y, PlaneExtent.Y);
		SpawnLocation = FVector(X, Y, 0.0f);
	}

	return SpawnLocation;
}

void ASmallBallSpawner::ApplyCardEffect(const FCardData& CardData)
{
	switch (CardData.EffectType)
	{
	case ECardEffectType::ModifySpawnRate:
		SpawnRate *= CardData.EffectValue;
		break;

	case ECardEffectType::ModifyMoveDirection:
		// DirectionModifier *= CardData.EffectValue; // Assuming DirectionModifier is FVector
		break;

	case ECardEffectType::ModifyMoveSpeed:
		// MoveSpeed *= CardData.EffectValue;
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("Unknown card effect type"));
		break;
	}
}

