// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE002_API UTitleUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Network")
	void StartServer();

	UFUNCTION(BlueprintCallable, Category = "Network")
	void Connect();

protected:

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network", meta = (AllowPrivateAccess = "true"))
	FString IP = TEXT("127.0.0.1");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network", meta = (AllowPrivateAccess = "true"))
	FString Port = TEXT("30000");
	
};
