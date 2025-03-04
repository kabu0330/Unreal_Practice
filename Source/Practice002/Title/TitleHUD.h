// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <Title/UI/TitleUserWidget.h>
#include "TitleHUD.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE002_API ATitleHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATitleHUD();
	~ATitleHUD();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float _DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UTitleUserWidget> Subclass = nullptr;
	
};
