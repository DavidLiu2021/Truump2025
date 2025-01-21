// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleGameModeBase.h"

ABubbleGameModeBase::ABubbleGameModeBase()
{
}

void ABubbleGameModeBase::InitCardPool()
{
}

void ABubbleGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	InitCardPool();
}

