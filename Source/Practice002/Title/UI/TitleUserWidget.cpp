// Fill out your copyright notice in the Description page of Project Settings.


#include "Title/UI/TitleUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include <Global/MyGlobal.h>

void UTitleUserWidget::StartServer()
{
	FString OpenLevel = TEXT("");
	FString LevelPath = TEXT(""); // 레벨의 폴더 경로를 저장할 변수

	UMyGlobal::AssetPackagePath(UWorld::StaticClass(), TEXT("PlayLevel"), LevelPath);
	OpenLevel = FString::Printf(TEXT(":%s%s"), *Port, *LevelPath); 
	// :30000/Game/Map/PlayLevel
	
	UGameplayStatics::OpenLevel(GetWorld(), *OpenLevel, true, TEXT("listen"));

	// Debug
	UE_LOG(LogTemp, Warning, TEXT("Port: %s, LevelPath: %s"), *Port, *LevelPath);
}

void UTitleUserWidget::Connect()
{
	FString ConnectLevelName = FString::Printf(TEXT("%s:%s"), *IP, *Port);
											// 127.0.0.1:30000

	UGameplayStatics::OpenLevel(GetWorld(), FName(*ConnectLevelName));

	// Debug
	UE_LOG(LogTemp, Warning, TEXT("ConnectLevelName: %s"), *ConnectLevelName);
}
