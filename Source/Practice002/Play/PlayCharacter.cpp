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
	NewRotation.Pitch = 0.0f;  // 상하 회전 고정
	NewRotation.Roll = 0.0f;   // 기울기 고정
	SetActorRotation(NewRotation);
}

void APlayCharacter::MoveFunction(const FVector2D& _Value)
{
	// Value.X = 앞/뒤
	// Value.Y = 좌/우
	
	// 1. 컨트롤러의 회전 값 가져와 좌우 회전값만 추출
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f); // Pitch : 상하 , Yaw : 좌우 , Roll : 기울기

	// 2. Yaw(좌우) 회전을 반영한 이동벡터 계산
	// GetUnitAxis : 크기가 1인 단위 벡터로 반환
	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // X는 상하
	const FVector Right   = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // Y는 좌우

	AddMovementInput(Forward, _Value.X); // 앞뒤 이동
	AddMovementInput(Right, _Value.Y); // 좌우 이동

	//CurAnimation = EPlayerState::RUN;
	ChangeAnimation(EPlayerState::RUN);
}

// Called to bind functionality to input
void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);


	// BP가 아니라 C++로 입력 처리하는 법
	//EnhancedInputComponent->BindActionValueLambda(MoveAction, ETriggerEvent::Triggered,
	//	[this](const FInputActionValue& _Value)
	//	{
	//		FVector
	//	});

}

