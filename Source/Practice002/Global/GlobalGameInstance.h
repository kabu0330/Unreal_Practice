// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <Play/Data/PlayLevelDataTable.h>
#include "GlobalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE002_API UGlobalGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	friend class UGlobalDataTable;

public:
	UGlobalGameInstance();
	~UGlobalGameInstance();

	UFUNCTION(BlueprintCallable, Category = "Random")
	FRandomStream& GetRandom()
	{
		return Random;
	}

protected:

private:
	UPROPERTY(VisibleAnywhere, Category = "Data")
	class UDataTable* DataTables = nullptr;

	class UDataTable* ActorDataTable = nullptr;

	class UDataTable* ItemDataTable = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Random")
	FRandomStream Random;
};
