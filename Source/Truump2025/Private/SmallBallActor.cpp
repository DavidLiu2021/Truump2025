// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBallActor.h"
#include "LargeBallActor.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PlayerController.h"

ASmallBallActor::ASmallBallActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	CollisionComponent->OnComponentHit.AddDynamic(this, &ASmallBallActor::OnHit);
	CollisionComponent->OnClicked.AddDynamic(this, &ASmallBallActor::OnClicked);

	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionComponent->SetNotifyRigidBodyCollision(true);
	CollisionComponent->SetSimulatePhysics(true);
	CollisionComponent->SetEnableGravity(false);

}

void ASmallBallActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASmallBallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveBall(DeltaTime);

}

void ASmallBallActor::OnClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	if (ALargeBallActor* LargeBall = Cast<ALargeBallActor>(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		LargeBall->OnSmallBallHit(-0.1f);
	}
	Destroy();
}

void ASmallBallActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ALargeBallActor* LargeBall = Cast<ALargeBallActor>(OtherActor))
	{
		LargeBall->OnSmallBallHit(0.1f);
		Destroy();
	}
}

void ASmallBallActor::MoveBall(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (MoveDirection * MoveSpeed * DeltaTime);
	// SetActorLocation(NewLocation);
	AddActorWorldOffset(MoveDirection * MoveSpeed * DeltaTime, true);
}

