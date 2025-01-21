// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "GameFramework/GameModeBase.h"
#include "BubbleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API ABubbleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABubbleGameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card Pool")
	TArray<FCardData> CardPool;

	virtual void InitCardPool();

protected:
	virtual void BeginPlay() override;

};


