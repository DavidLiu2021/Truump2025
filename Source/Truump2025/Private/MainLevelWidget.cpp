// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelWidget.h"
#include "Components/Button.h"
#include "CardSelectionWidget.h"
#include "Components/ProgressBar.h"


void UMainLevelWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CardButton)
	{
		CardButton->OnClicked.AddDynamic(this, &UMainLevelWidget::OnButtonClicked);
	}
}

void UMainLevelWidget::UpdateProgressBar(float Progress)
{
	if (ProgressBar)
	{
		ProgressBar->SetPercent(Progress);
	}
}

void UMainLevelWidget::OnButtonClicked()
{
	UCardSelectionWidget* CardSelectionWidget = CreateWidget<UCardSelectionWidget>(GetWorld(), UCardSelectionWidget::StaticClass());
	if (CardSelectionWidget)
	{
		CardSelectionWidget->AddToViewport();
		
	}
	this->SetVisibility(ESlateVisibility::Hidden);
}
