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
	// 1. BP Ŭ������ ������ ���̺� ����ϰ� C++�� �����´�.
	TSubclassOf<AActor> Subclass = UGlobalDataTable::GetActorClass(GetWorld(), TEXT("BP_WeaponItem"));
	FTransform Trans;

	// 2. BP Ŭ������ �����Ѵ�.
	AWeaponItem* WeaponItem = GetWorld()->SpawnActorDeferred<AWeaponItem>(Subclass, Trans);

	// ������� �ۼ��� �ڵ�� ���忡 ���� ����
	if (nullptr == WeaponItem)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == ItemActor) Item Spawn Is Nullptr"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	// 3. ItemDataRow�� ����ص� �޽÷� �ٲ۴�. => Item���� �˾Ƽ� �ض�
	WeaponItem->SetItemDataKey(ItemName);

	WeaponItem->FinishSpawning(Trans); // ���������� �����ϰ� ���忡 ����

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

