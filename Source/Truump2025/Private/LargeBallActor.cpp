// Fill out your copyright notice in the Description page of Project Settings.


#include "LargeBallActor.h"
#include "SmallBallActor.h"
#include "Components/SphereComponent.h"

// Sets default values
ALargeBallActor::ALargeBallActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	CollisionComponent->SetNotifyRigidBodyCollision(true);

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ALargeBallActor::OnOverlapBegin);
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

void ALargeBallActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
									 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
									 bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("555: %s"), *OtherActor->GetName());
	if (ASmallBallActor* SmallBall = Cast<ASmallBallActor>(OtherActor))
	{
		OnSmallBallHit(0.1f);
		SmallBall->Destroy(); 
	}
}

