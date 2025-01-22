// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleBaseUserWidget.h"

void UBubbleBaseUserWidget::ShowUI()
{
	SetVisibility(ESlateVisibility::Visible);
}

void UBubbleBaseUserWidget::HideUI()
{
	SetVisibility(ESlateVisibility::Hidden);
}
