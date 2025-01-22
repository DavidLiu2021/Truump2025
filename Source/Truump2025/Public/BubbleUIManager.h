// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BubbleBaseUserWidget.h"
#include "BubbleUIManager.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API UBubbleUIManager : public UObject
{
	GENERATED_BODY()

private:
	TMap<FName, UBubbleBaseUserWidget*> UIWidgets;
	
public:
	UFUNCTION(BlueprintCallable, Category="UI")
	void RegisterUI(FName UIName, UBubbleBaseUserWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="UI")
	void ShowUI(FName UIName);

	UFUNCTION(BlueprintCallable, Category="UI")
	void HideUI(FName UIName);
	
};
