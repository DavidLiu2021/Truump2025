// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "UObject/NoExportTypes.h"
#include "CardDataManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TRUUMP2025_API UCardDataManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	TArray<FCardData> AllCards;

	UFUNCTION(BlueprintCallable, Category = "Card")
	TArray<FCardData> GetAllCards() const;

	void InitializeCardData();
};
