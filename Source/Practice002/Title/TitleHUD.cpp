// Fill out your copyright notice in the Description page of Project Settings.


#include "Title/TitleHUD.h"


ATitleHUD::ATitleHUD()
{
}

ATitleHUD::~ATitleHUD()
{
}

void ATitleHUD::BeginPlay()
{
	Super::BeginPlay();

	UTitleUserWidget* TitleWidget = CreateWidget<UTitleUserWidget>(GetWorld(), Subclass);
	if (nullptr == TitleWidget)
	{
		return;
	}
	TitleWidget->AddToViewport();

}

void ATitleHUD::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
