// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CheckPointInterface.h"
#include "CheckPointWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API UCheckPointWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ProgressBar;

	UPROPERTY(meta = (BindWidget))
	class UButton* ConfirmButton;

	UPROPERTY()
	TScriptInterface<ICheckPointInterface> CheckPointInterface;

	virtual void NativeConstruct() override;
	void UpdateProgressBar(float Progress);

private:
	UFUNCTION()
	void ConfirmButtonClicked();
};
