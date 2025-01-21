// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameCamera.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACardGameCamera::ACardGameCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;

	CameraComponent->SetWorldLocation(FVector(0.f, 0.f, 500.f));
	CameraComponent->SetWorldRotation(FRotator(-45.f, 0.f, 0.f));

}

// Called when the game starts or when spawned
void ACardGameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACardGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

