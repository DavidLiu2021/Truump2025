// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "CheckPointWidget.h"
#include "MainLevelWidget.h"
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

	// Initiate the Main Level Widget
	if (MainLevelWidgetClass)
	{
		MainLevelWidget = CreateWidget<UMainLevelWidget>(GetWorld(), MainLevelWidgetClass);
		if (MainLevelWidget)
		{
			// MainLevelWidget->CheckPointInterface = this;
			MainLevelWidget->AddToViewport();
		}
	}
	GetWorld()->GetTimerManager().SetTimer(ProgressTimerHandle, this, &ABubbleGameModeBase::UpdateProgress, 1.0f, true);

	if (CheckPointWidgetClass)
	{
		CheckPointWidget = CreateWidget<UCheckPointWidget>(GetWorld(), CheckPointWidgetClass);
		if (CheckPointWidget)
		{
			CheckPointWidget->CheckPointInterface = this;
			CheckPointWidget->AddToViewport();
			CheckPointWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

// In Check Point Widget, On Confirm to hide interface
void ABubbleGameModeBase::OnConfirm()
{
	bIsCheckpointActive = false;
	
	if (CheckPointWidget)
	{
		CheckPointWidget->SetVisibility(ESlateVisibility::Hidden);
		MainLevelWidget->SetVisibility(ESlateVisibility::Visible);
	}
	
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

// Update Main Level's Progress Bar
void ABubbleGameModeBase::UpdateProgress()
{
	if (bIsCheckpointActive)
	{
		return;
	}

	CurrentProgress += 1.0f / 60.0f;
	if (MainLevelWidget)
	{
		MainLevelWidget->UpdateProgressBar(CurrentProgress);
	}

	if (CurrentProgress >= 1.0f)
	{
		CurrentProgress = 0.0f;
		ShowCheckPointUI();
		MainLevelWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

// Show Check Point Widget
void ABubbleGameModeBase::ShowCheckPointUI()
{
	if (CheckPointWidget)
	{
		CheckPointWidget->SetVisibility(ESlateVisibility::Visible);
		bIsCheckpointActive = true;
	}
	
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

