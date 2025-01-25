// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallBallActor.h"
// #include "LargeBallActor.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"

ASmallBallActor::ASmallBallActor()
{
	PrimaryActorTick.bCanEverTick = true;

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

/*void ASmallBallActor::OnClicked(AActor* ClickedActor)
{
	if (ALargeBallActor* LargeBall = Cast<ALargeBallActor>(GetWorld()->GetFirstPlayerController()->GetPawn()))
	{
		LargeBall->OnSmallBallHit(-0.1f);
	}
	Destroy();
}

void ASmallBallActor::OnHit(AActor* OtherActor)
{
	if (ALargeBallActor* LargeBall = Cast<ALargeBallActor>(OtherActor))
	{
		LargeBall->OnSmallBallHit(0.1f);
		Destroy();
	}
}*/

void ASmallBallActor::MoveBall(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (MoveDirection * MoveSpeed * DeltaTime);
	SetActorLocation(NewLocation);
}

