// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayGameMode.h"
#include <Play/Manager/ItemManager.h>

APlayGameMode::APlayGameMode() : Super()
{
	ItemManager = CreateDefaultSubobject<UItemManager>(TEXT("ItemManager"));
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();

	AActor* NewDropItem = ItemManager->CreateItem(TEXT("Staff"));
	if (nullptr != NewDropItem)
	{
		NewDropItem->SetActorLocation(FVector(300.0f, 300.0f, 50.0f));
	}
}

void APlayGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
