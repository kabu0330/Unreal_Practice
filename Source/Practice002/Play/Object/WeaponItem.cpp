// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/Object/WeaponItem.h"
#include "Global/Data/GlobalDataTable.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AWeaponItem::AWeaponItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Tags.Add(TEXT("Item"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->Mobility = EComponentMobility::Movable;
	StaticMeshComponent->SetGenerateOverlapEvents(true);
	RootComponent = StaticMeshComponent;


	// StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	//StaticMeshComponent->SetCollisionProfileName(UGMConst::Collision::ProfileName_Event);
	// StaticMeshComponent->bUseDefaultCollision = true;

}

// Called when the game starts or when spawned
void AWeaponItem::BeginPlay()
{
	Super::BeginPlay();
	
	if (ItemDataKey == TEXT("") || true == ItemDataKey.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> 아이템 데이터 키가 없습니다."), __FUNCTION__, __LINE__);
		return;
	}

	const FItemDataRow* Data = UGlobalDataTable::GetItemData(GetWorld(), ItemDataKey);
	ItemData = Data;
	GetStaticMeshComponent()->SetStaticMesh(Data->Mesh); // 여기서 메시 설정
}

// Called every frame
void AWeaponItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeaponItem, ItemDataKey);
}

