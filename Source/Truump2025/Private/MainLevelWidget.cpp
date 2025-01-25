// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLevelWidget.h"
#include "Components/ProgressBar.h"


void UMainLevelWidget::UpdateProgressBar(float Progress)
{
	if (ProgressBar)
	{
		ProgressBar->SetPercent(Progress);
	}
}
