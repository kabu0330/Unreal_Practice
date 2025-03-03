// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalGameInstance.h"
#include <Play/Data/PlayLevelDataTable.h>
#include <Global/Data/GlobalDataTable.h>

UGlobalGameInstance::UGlobalGameInstance()
{
	FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BP/Global/Data/DT_DataTableRow.DT_DataTableRow'");
	ConstructorHelpers::FObjectFinder<UDataTable> FinderDataTable(*DataPath);
	if (true == FinderDataTable.Succeeded())
	{
		DataTables = FinderDataTable.Object;
	}

	if (nullptr != DataTables)
	{
		// 블루프린트 객체를 C++로 가져오기 위함
		ActorDataTable = DataTables->FindRow<FDataTableRow>("DT_GlobalActorDataRow", nullptr)->Resources;
		if (nullptr == ActorDataTable)
		{
			UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == ActorDataTable)"), __FUNCTION__, __LINE__);
		}
	}

	if (nullptr != DataTables)
	{
		ItemDataTable = DataTables->FindRow<FDataTableRow>("DT_ItemDataRow", nullptr)->Resources;
		if (nullptr == ItemDataTable)
		{
			UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == ItemDataTable)"), __FUNCTION__, __LINE__);
		}
	}

}

UGlobalGameInstance::~UGlobalGameInstance()
{
}
