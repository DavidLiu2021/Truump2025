// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "CardDataManager.h"
#include "GameFramework/GameModeBase.h"
#include "CheckPointInterface.h"
#include "BubbleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API ABubbleGameModeBase : public AGameModeBase, public ICheckPointInterface
{
	GENERATED_BODY()

public:
	ABubbleGameModeBase();

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card Pool")
	TArray<FCardData> CardPool;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Card")
	UCardDataManager* CardDataManager;

	virtual void InitCardPool();

protected:
	virtual void BeginPlay() override;

	virtual void OnConfirm() override;

private:
	UPROPERTY()
	class UCheckPointWidget* CheckPointWidget;

	UPROPERTY()
	class UMainLevelWidget* MainLevelWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> CheckPointWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainLevelWidgetClass;

	FTimerHandle ProgressTimerHandle;
	float CurrentProgress;
	bool bIsCheckpointActive;

	void UpdateProgress();
	void ShowCheckPointUI();

};


