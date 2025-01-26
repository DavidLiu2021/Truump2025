// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmallBallActor.generated.h"

 class USphereComponent;

UCLASS()
class TRUUMP2025_API ASmallBallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASmallBallActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Ball Properties")
	FVector MoveDirection = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Ball Properties")
	float MoveSpeed = 200.0f;

	UFUNCTION()
	void OnClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	/*UFUNCTION()
	void OnHit(AActor* OtherActor);*/

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void MoveBall(float DeltaTime);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* CollisionComponent;

};
