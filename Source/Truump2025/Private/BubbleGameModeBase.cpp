// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "CheckPointWidget.h"
#include "Kismet/GameplayStatics.h"

ABubbleGameModeBase::ABubbleGameModeBase()
{
	CurrentProgress = 0.0f;
	bIsCheckpointActive = false;
}

void ABubbleGameModeBase::InitCardPool()
{
}

void ABubbleGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	InitCardPool();

	if (CheckPointWidgetClass)
	{
		CheckPointWidget = CreateWidget<UCheckPointWidget>(GetWorld(), CheckPointWidgetClass);
		if (CheckPointWidget)
		{
			CheckPointWidget->CheckPointInterface = this;
			CheckPointWidget->AddToViewport();
		}
	}
	GetWorld()->GetTimerManager().SetTimer(ProgressTimerHandle, this, &ABubbleGameModeBase::UpdateProgress, 1.0f, true);
}

void ABubbleGameModeBase::OnConfirm()
{
	bIsCheckpointActive = false;
	
	if (CheckPointWidget)
	{
		CheckPointWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void ABubbleGameModeBase::UpdateProgress()
{
	if (bIsCheckpointActive)
	{
		return;
	}

	CurrentProgress += 1.0f / 60.0f;
	if (CheckPointWidget)
	{
		CheckPointWidget->UpdateProgressBar(CurrentProgress);
	}

	if (CurrentProgress >= 1.0f)
	{
		CurrentProgress = 0.0f;
		ShowCheckPointUI();
	}
}

void ABubbleGameModeBase::ShowCheckPointUI()
{
	bIsCheckpointActive = true;
	
	if (CheckPointWidget)
	{
		CheckPointWidget->SetVisibility(ESlateVisibility::Visible);
	}
	
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

