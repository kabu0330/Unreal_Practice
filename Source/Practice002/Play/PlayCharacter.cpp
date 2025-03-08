// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include <Play/PlayGameMode.h>
#include <Play/Manager/ItemManager.h>
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

// Sets default values
APlayCharacter::APlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	bReplicates = true;

}

void APlayCharacter::CheckOverlap(AActor* Actor)
{
	if (true == Actor->ActorHasTag(TEXT("Item")))
	{
		//UGameplayStatics::GetAllActorsWithTag()
		Actor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("WeaponSocket"));
	}
}

void APlayCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayCharacter, CurAnimation);
}

//void APlayCharacter::ChangeAnimation(EPlayerAnimation CurPlayerAnimation)
//{
//}

void APlayCharacter::ChangeAnimation_Implementation(EPlayerState CurPlayerAnimation)
{
	CurAnimation = CurPlayerAnimation;
}

// Called when the game starts or when spawned
void APlayCharacter::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* GameMode = Cast<AGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	APlayGameMode* PlayGameMode = nullptr;
	if (nullptr != GameMode)
	{
		PlayGameMode = Cast<APlayGameMode>(GameMode);
		if (nullptr == PlayGameMode)
		{
			return;
		}
	}

	if (nullptr != PlayGameMode)
	{
		UItemManager* ItemManager = PlayGameMode->GetItemManager();
		if (nullptr != ItemManager)
		{
			AActor* NewDropItem = ItemManager->CreateItem(TEXT("Staff"));
			if (nullptr != NewDropItem)
			{
				NewDropItem->SetActorLocation(FVector(300.0f, 300.0f, 50.0f));
			}
		}
	}

}

// Called every frame
void APlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation();
	NewRotation.Pitch = 0.0f;  // ���� ȸ�� ����
	NewRotation.Roll = 0.0f;   // ���� ����
	SetActorRotation(NewRotation);
}

void APlayCharacter::MoveFunction(const FVector2D& _Value)
{
	// Value.X = ��/��
	// Value.Y = ��/��
	
	// 1. ��Ʈ�ѷ��� ȸ�� �� ������ �¿� ȸ������ ����
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f); // Pitch : ���� , Yaw : �¿� , Roll : ����

	// 2. Yaw(�¿�) ȸ���� �ݿ��� �̵����� ���
	// GetUnitAxis : ũ�Ⱑ 1�� ���� ���ͷ� ��ȯ
	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // X�� ����
	const FVector Right   = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // Y�� �¿�

	AddMovementInput(Forward, _Value.X); // �յ� �̵�
	AddMovementInput(Right, _Value.Y); // �¿� �̵�

	//CurAnimation = EPlayerState::RUN;
	ChangeAnimation(EPlayerState::RUN);
}

// Called to bind functionality to input
void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);


	// BP�� �ƴ϶� C++�� �Է� ó���ϴ� ��
	//EnhancedInputComponent->BindActionValueLambda(MoveAction, ETriggerEvent::Triggered,
	//	[this](const FInputActionValue& _Value)
	//	{
	//		FVector
	//	});

}

