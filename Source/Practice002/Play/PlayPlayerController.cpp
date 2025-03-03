// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayPlayerController.h"
#include "PlayPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayPlayerController::APlayPlayerController()
{
}

// 기존 입력 매핑을 초기화하고 새로운 입력 매핑을 적용
// 매개변수 MappingContext는 에디터에서 블루프린터로 해당 함수를 호출하여 지정해준다.
void APlayPlayerController::AddMappingContext(UInputMappingContext* MappingContext)
{
	ULocalPlayer* NewPlayer = GetLocalPlayer(); // 현재 플레이어 객체
	if (nullptr == NewPlayer)
	{
		return;
	}
	// 1. 현재 플레이어 NewPlayer 객체에서 입력 시스템(UEnhancedInputLocalPlayerSubsystem)을 가져온다.
	// 입력 시스템 : UE5 입력 시스템은 플레이어 별로 입력 매핑을 다룬다. 기존 버전과 차이가 있어 향상된(Enhanced)을 사용한다.
	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(NewPlayer);

	
	InputSystem->ClearAllMappings(); // 2. 현재 NewPlayer의 모든 입력 매핑을 초기화한다.
	InputSystem->AddMappingContext(MappingContext, 0); // 3. 새로운 입력 매핑 컨텍스트를 추가하고 0번째 입력 우선순위로 지정한다.

}

void APlayPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void APlayPlayerController::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void APlayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
