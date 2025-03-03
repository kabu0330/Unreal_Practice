// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayGameMode.h"
#include <Play/Manager/ItemManager.h>

APlayGameMode::APlayGameMode() : Super()
{
	ItemManager = CreateDefaultSubobject<UItemManager>(TEXT("ItemManager"));
}
