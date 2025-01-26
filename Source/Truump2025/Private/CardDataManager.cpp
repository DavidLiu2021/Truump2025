// Fill out your copyright notice in the Description page of Project Settings.


#include "CardDataManager.h"
#include "CardData.h"

TArray<FCardData> UCardDataManager::GetAllCards() const
{
	return AllCards;
}

void UCardDataManager::InitializeCardData()
{
	AllCards.Add(FCardData(TEXT("Card 1"), nullptr, 3, ECardEffectType::ModifySpawnRate, 1.0f));
}
