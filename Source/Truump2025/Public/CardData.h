#pragma once

#include "CoreMinimal.h"
#include "CardData.generated.h"

USTRUCT(BlueprintType)
struct FCardData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card")
	FString CardName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card")
	UTexture2D* CardImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card")
	int32 ColdDown;

	FCardData()
		: CardName(TEXT("DefaultName"))
		, CardImage(nullptr)
		, ColdDown(3)
	{
		
	}
	
};
