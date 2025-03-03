// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/Data/GlobalDataTable.h"
#include <Global/GlobalGameInstance.h>

TSubclassOf<AActor> UGlobalDataTable::GetActorClass(UWorld* World, const FString& Name)
{
	UGlobalGameInstance* GameInst = World->GetGameInstance<UGlobalGameInstance>();
	if (nullptr == GameInst->ActorDataTable)
	{
		return nullptr;
	}

	FActorClassTableRow* Data = GameInst->ActorDataTable->FindRow<FActorClassTableRow>(*Name, nullptr);
	if (nullptr == Data)
	{
		return nullptr;
	}

	return Data->SpawnClass;
}

const FItemDataRow* UGlobalDataTable::GetItemData(UWorld* World, const FString& Name)
{
	UGlobalGameInstance* GameInst = World->GetGameInstance<UGlobalGameInstance>();

	if (nullptr == GameInst->ItemDataTable)
	{
		return nullptr;
	}

	FItemDataRow* Data = GameInst->ItemDataTable->FindRow<FItemDataRow>(*Name, nullptr);
	if (nullptr == Data)
	{
		return nullptr;
	}

	return Data;
}
