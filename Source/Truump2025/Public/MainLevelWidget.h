// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainLevelWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API UMainLevelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ProgressBar;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton;

	void UpdateProgressBar(float Progress);
	void OnButtonClicked();
	
};
