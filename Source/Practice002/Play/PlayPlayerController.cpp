// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayPlayerController.h"
#include "PlayPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayPlayerController::APlayPlayerController()
{
}

// ���� �Է� ������ �ʱ�ȭ�ϰ� ���ο� �Է� ������ ����
// �Ű����� MappingContext�� �����Ϳ��� ��������ͷ� �ش� �Լ��� ȣ���Ͽ� �������ش�.
void APlayPlayerController::AddMappingContext(UInputMappingContext* MappingContext)
{
	ULocalPlayer* NewPlayer = GetLocalPlayer(); // ���� �÷��̾� ��ü
	if (nullptr == NewPlayer)
	{
		return;
	}
	// 1. ���� �÷��̾� NewPlayer ��ü���� �Է� �ý���(UEnhancedInputLocalPlayerSubsystem)�� �����´�.
	// �Է� �ý��� : UE5 �Է� �ý����� �÷��̾� ���� �Է� ������ �ٷ��. ���� ������ ���̰� �־� ����(Enhanced)�� ����Ѵ�.
	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(NewPlayer);

	
	InputSystem->ClearAllMappings(); // 2. ���� NewPlayer�� ��� �Է� ������ �ʱ�ȭ�Ѵ�.
	InputSystem->AddMappingContext(MappingContext, 0); // 3. ���ο� �Է� ���� ���ؽ�Ʈ�� �߰��ϰ� 0��° �Է� �켱������ �����Ѵ�.

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
