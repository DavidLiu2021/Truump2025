// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmallBallSpawner.h"
#include "Blueprint/UserWidget.h"
#include "CardSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class TRUUMP2025_API UCardSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="References")
	ASmallBallSpawner* SmallBallSpawnerRef;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton1;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton2;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton3;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton4;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton5;

	UPROPERTY(meta = (BindWidget))
	class UButton* CardButton6;

private:
	UFUNCTION()
	void CardSelect1();

	UFUNCTION()
	void CardSelect2();

	UFUNCTION()
	void CardSelect3();

	UFUNCTION()
	void CardSelect4();

	UFUNCTION()
	void CardSelect5();

	UFUNCTION()
	void CardSelect6();
	
};
