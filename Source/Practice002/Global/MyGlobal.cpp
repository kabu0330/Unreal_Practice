// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/MyGlobal.h"
#include "AssetRegistry/AssetRegistryModule.h"

TArray<FAssetData> UMyGlobal::AssetPath(UClass* Class)
{
	TArray<FAssetData> AssetList;
	
	if (false == FModuleManager::Get().IsModuleLoaded("AssetRegistry")) // AssetRegistry 모듈 로드됐어?
	{
		return AssetList; // (실패)
	}

	IAssetRegistry& AssetRegistry = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	if (true == AssetRegistry.IsLoadingAssets()) // 에셋이 로딩 중이면 리턴
	{
		return AssetList; // (실패) AssetRegistry는 비동기적으로 에셋을 로드할 수 있기 때문에 로딩 중에는 이상한 결과값이 들어갈 수 있다.
	}

	if (true == AssetRegistry.GetAssetsByClass(Class->GetClassPathName(), AssetList))
	{
		return AssetList; // (성공) 정상적으로 AssetList가 담긴 상태
	}

	return AssetList; // (실패) 불완전한 에셋 정보가 담긴 상태
}

// 에셋이 속한 폴더(Package) 경로를 찾아주는 함수
// ObjectPath : PackagePath/AssetName
void UMyGlobal::AssetPackagePath(UClass* Class, const FString& AssetName, FString& Path)
{
	// 1. 해당 클래스의 에셋 데이터(이름, 경로, 클래스 등)를 가져온다.
	TArray<FAssetData> AllAsset = AssetPath(Class);

	// 2. 찾고자하는 에셋 이름을 해당 에셋 데이터 리스트에서 추출한다.
	FName CheckName = FName(*AssetName); 

	for (const FAssetData& AssetData : AllAsset)
	{	
		if (CheckName == AssetData.AssetName)
		{
			Path = AssetData.PackageName.ToString(); // 3. 세 번째 매개변수에 에셋의 경로를 저장하고 리턴
			return;
		}
	}
}
