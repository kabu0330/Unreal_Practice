// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyGlobal.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE002_API UMyGlobal : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static TArray<FAssetData> AssetPath(UClass* Class);
	
	// AssetName 넣어주면 경로 찾아서 Path에 저장해주는 함수
	UFUNCTION(BlueprintCallable)
	static void AssetPackagePath(UClass* Class, const FString& AssetName, FString& Path);

};
