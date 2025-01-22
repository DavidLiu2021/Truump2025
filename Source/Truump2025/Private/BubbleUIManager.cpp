// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleUIManager.h"

void UBubbleUIManager::RegisterUI(FName UIName, UBubbleBaseUserWidget* Widget)
{
	if (Widget && !UIWidgets.Contains(UIName))
	{
		UIWidgets.Add(UIName, Widget);
	}
}

void UBubbleUIManager::ShowUI(FName UIName)
{
	if (UIWidgets.Contains(UIName))
	{
		UIWidgets[UIName]->ShowUI();
	}
}

void UBubbleUIManager::HideUI(FName UIName)
{
	if (UIWidgets.Contains(UIName))
	{
		UIWidgets[UIName]->HideUI();
	}
}
