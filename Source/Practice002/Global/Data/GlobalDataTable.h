// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Play/Data/PlayLevelDataTable.h>
#include "GlobalDataTable.generated.h"

USTRUCT(BlueprintType)
struct FDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FDataTableRow() {}
	~FDataTableRow() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UDataTable* Resources;
};

USTRUCT(BlueprintType)
struct FActorClassTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FActorClassTableRow() {}
	~FActorClassTableRow() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TSubclassOf<class AActor> SpawnClass;
};

/**
 * 
 */
UCLASS()
class PRACTICE002_API UGlobalDataTable : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 블루프린트 클래스를 C++로 가져오는 함수
	static TSubclassOf<AActor> GetActorClass(UWorld* World, const FString& Name);

	static const FItemDataRow* GetItemData(UWorld* World, const FString& Name);
};

