// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LargeBallActor.generated.h"

UCLASS()
class TRUUMP2025_API ALargeBallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALargeBallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSmallBallHit(float SizeChange);

	void ChangeSize(float SizeDelta);

private:
	UPROPERTY(EditAnywhere, Category = "Ball Properties")
	float SizeMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Ball Properties")
	FVector InitialScale;

};
