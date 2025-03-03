// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/Object/WeaponItem.h"

// Sets default values
AWeaponItem::AWeaponItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	
}

// Called every frame
void AWeaponItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

