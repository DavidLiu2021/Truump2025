// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPointWidget.h"
#include "Components/Button.h"

void UCheckPointWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ConfirmButton)
	{
		ConfirmButton->OnClicked.AddDynamic(this, &UCheckPointWidget::ConfirmButtonClicked);
	}
}

/*void UCheckPointWidget::UpdateProgressBar(float Progress)
{
	if (ProgressBar)
	{
		ProgressBar->SetPercent(Progress);
	}
}*/

void UCheckPointWidget::ConfirmButtonClicked()
{
	if (CheckPointInterface)
	{
		CheckPointInterface->OnConfirm();
	}
}
