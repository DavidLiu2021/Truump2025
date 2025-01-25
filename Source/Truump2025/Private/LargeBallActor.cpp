// Fill out your copyright notice in the Description page of Project Settings.


#include "LargeBallActor.h"

// Sets default values
ALargeBallActor::ALargeBallActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ALargeBallActor::BeginPlay()
{
	Super::BeginPlay();
	InitialScale = GetActorScale3D(); // The initial scale of the large ball
	
}

void ALargeBallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALargeBallActor::OnSmallBallHit(float SizeChange)
{
	ChangeSize(SizeChange);
}

void ALargeBallActor::ChangeSize(float SizeDelta)
{
	FVector NewScale = GetActorScale3D() + FVector(SizeDelta * SizeMultiplier);
	NewScale = FVector(FMath::Max(0.1f, NewScale.X), FMath::Max(0.1f, NewScale.Y), FMath::Max(0.1f, NewScale.Z));
	SetActorScale3D(NewScale);
}

