// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BubbleBaseUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API UBubbleBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowUI();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideUI();
	
};
