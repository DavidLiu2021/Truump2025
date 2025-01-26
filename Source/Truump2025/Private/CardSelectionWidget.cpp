// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSelectionWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UCardSelectionWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (CardButton1)
	{
		CardButton1->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect1);
	}

	if (CardButton2)
	{
		CardButton2->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect2);
	}

	if (CardButton3)
	{
		CardButton3->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect3);
	}

	if (CardButton4)
	{
		CardButton4->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect4);
	}

	if (CardButton5)
	{
		CardButton5->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect5);
	}

	if (CardButton6)
	{
		CardButton6->OnClicked.AddDynamic(this, &UCardSelectionWidget::CardSelect6);
	}

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASmallBallSpawner::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		SmallBallSpawnerRef = Cast<ASmallBallSpawner>(FoundActors[0]);
	}
}

void UCardSelectionWidget::CardSelect1()
{
	if (SmallBallSpawnerRef)
	{
		SmallBallSpawnerRef->SpawnRate = 1.2f;
	}
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::CardSelect2()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::CardSelect3()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::CardSelect4()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::CardSelect5()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}

void UCardSelectionWidget::CardSelect6()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}
