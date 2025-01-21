// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "CardGameCamera.h"


void ABubblePlayerController::BeginPlay()
{
	Super::BeginPlay();

	ACardGameCamera* FixedCamera = Cast<ACardGameCamera>(
		UGameplayStatics::GetActorOfClass(GetWorld(), ACardGameCamera::StaticClass())
		);

	if (FixedCamera)
	{
		SetViewTargetWithBlend(FixedCamera, 0.0f);
	}

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}
