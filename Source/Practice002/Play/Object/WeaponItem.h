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

	// Network
	void SetItemDataKey(const FString& DataKey)
	{
		ItemDataKey = DataKey;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Network
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

private:	
	// Network
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Network", meta = (AllowPrivateAccess = "true"))
	FString ItemDataKey = "";


	const FItemDataRow* ItemData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;
};
