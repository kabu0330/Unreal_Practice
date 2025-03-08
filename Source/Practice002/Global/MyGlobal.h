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
	
	// AssetName �־��ָ� ��� ã�Ƽ� Path�� �������ִ� �Լ�
	UFUNCTION(BlueprintCallable)
	static void AssetPackagePath(UClass* Class, const FString& AssetName, FString& Path);

};
