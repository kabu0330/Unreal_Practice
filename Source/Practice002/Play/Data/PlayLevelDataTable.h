// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayLevelDataTable.generated.h"

USTRUCT(BlueprintType)
struct FItemDataRow : public FTableRowBase
{
	GENERATED_BODY()

	FItemDataRow() {}
	~FItemDataRow() {}

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int Att = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UStaticMesh* Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FVector EquipPos = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FVector EquipAngle = FVector::ZeroVector;
};


/**
 * 
 */
UCLASS()
class PRACTICE002_API UPlayLevelDataTable : public UObject
{
	GENERATED_BODY()
	
};
