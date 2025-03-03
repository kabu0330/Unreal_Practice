// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/Manager/ItemManager.h"
#include <Global/Data/GlobalDataTable.h>
#include <Play/Object/WeaponItem.h>

// Sets default values for this component's properties
UItemManager::UItemManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UItemManager::CreateItem(const FString& ItemName)
{
	// 1. BP 클래스를 데이터 테이블에 등록하고 C++로 가져온다.
	TSubclassOf<AActor> Subclass = UGlobalDataTable::GetActorClass(GetWorld(), TEXT("BP_WeaponItem"));

	// 2. BP 클래스를 스폰한다.
	AWeaponItem* WeaponItem = GetWorld()->SpawnActor<AWeaponItem>(Subclass);
	if (nullptr == WeaponItem)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == ItemActor) Item Spawn Is Nullptr"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	// 3. ItemDataRow에 등록해둔 메시로 바꾼다.
	const FItemDataRow* Data = UGlobalDataTable::GetItemData(GetWorld(), ItemName);
	WeaponItem->ItemData = Data; 
	WeaponItem->GetStaticMeshComponent()->SetStaticMesh(Data->Mesh);

	return WeaponItem;
}

// Called when the game starts
void UItemManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

