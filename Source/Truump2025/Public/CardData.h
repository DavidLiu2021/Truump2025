#pragma once

#include "CoreMinimal.h"
// #include "SmallBallSpawner.h"
#include "CardData.generated.h"

UENUM(BlueprintType)
enum class ECardEffectType : uint8
{
	ModifySpawnRate UMETA(DisplayName = "Modify Spawn Rate"),
	ModifyMoveDirection UMETA(DisplayName = "Modify Move Direction"),
	ModifyMoveSpeed UMETA(DisplayName = "Modify Move Speed"),
	ModifyCD UMETA(DisplayName = "Modify card CD")
};

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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card")
	ECardEffectType EffectType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card")
	float EffectValue;

	// default card
	FCardData()
		: CardName(TEXT("DefaultName"))
		, CardImage(nullptr)
		, ColdDown(3)
		, EffectType(ECardEffectType::ModifySpawnRate)
		, EffectValue(1.0f)
	{
		
	}

	FCardData(const FString& InName, UTexture2D* InImage, int32 InColdDown, ECardEffectType InEffectType, float InEffectValue)
		: CardName(InName)
		, CardImage(InImage)
		, ColdDown(InColdDown)
		, EffectType(InEffectType)
		, EffectValue(InEffectValue)
	{
	}
	
};
