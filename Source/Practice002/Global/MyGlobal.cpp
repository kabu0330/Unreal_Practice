// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/MyGlobal.h"
#include "AssetRegistry/AssetRegistryModule.h"

TArray<FAssetData> UMyGlobal::AssetPath(UClass* Class)
{
	TArray<FAssetData> AssetList;
	
	if (false == FModuleManager::Get().IsModuleLoaded("AssetRegistry")) // AssetRegistry ��� �ε�ƾ�?
	{
		return AssetList; // (����)
	}

	IAssetRegistry& AssetRegistry = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	if (true == AssetRegistry.IsLoadingAssets()) // ������ �ε� ���̸� ����
	{
		return AssetList; // (����) AssetRegistry�� �񵿱������� ������ �ε��� �� �ֱ� ������ �ε� �߿��� �̻��� ������� �� �� �ִ�.
	}

	if (true == AssetRegistry.GetAssetsByClass(Class->GetClassPathName(), AssetList))
	{
		return AssetList; // (����) ���������� AssetList�� ��� ����
	}

	return AssetList; // (����) �ҿ����� ���� ������ ��� ����
}

// ������ ���� ����(Package) ��θ� ã���ִ� �Լ�
// ObjectPath : PackagePath/AssetName
void UMyGlobal::AssetPackagePath(UClass* Class, const FString& AssetName, FString& Path)
{
	// 1. �ش� Ŭ������ ���� ������(�̸�, ���, Ŭ���� ��)�� �����´�.
	TArray<FAssetData> AllAsset = AssetPath(Class);

	// 2. ã�����ϴ� ���� �̸��� �ش� ���� ������ ����Ʈ���� �����Ѵ�.
	FName CheckName = FName(*AssetName); 

	for (const FAssetData& AssetData : AllAsset)
	{	
		if (CheckName == AssetData.AssetName)
		{
			Path = AssetData.PackageName.ToString(); // 3. �� ��° �Ű������� ������ ��θ� �����ϰ� ����
			return;
		}
	}
}
