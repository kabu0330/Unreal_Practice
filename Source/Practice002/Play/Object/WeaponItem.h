// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Play/Data/PlayLevelDataTable.h>
#include "WeaponItem.generated.h"

UCLASS()
class PRACTICE002_API AWeaponItem : public AActor
{
	GENERATED_BODY()

	friend class UItemManager;
	
public:	
	// Sets default values for this actor's properties
	AWeaponItem();

	class UStaticMeshComponent* GetStaticMeshComponent()
	{
		return StaticMeshComponent.Get();
	}

	const FItemDataRow* GetItemData()
	{
		return ItemData;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	
	const FItemDataRow* ItemData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;
};
