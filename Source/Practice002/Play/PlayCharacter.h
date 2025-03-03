// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayCharacter.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	NONE   UMETA(DisplayName = "NONE"),
	IDLE   UMETA(DisplayName = "대기"),
	RUN    UMETA(DisplayName = "달리기"),
	ATTACK UMETA(DisplayName = "공격"),
	MAX    UMETA(DisplayName = "MAX"),
};


UCLASS()
class PRACTICE002_API APlayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayCharacter();

	UFUNCTION(BlueprintCallable)
	void MoveFunction(const FVector2D& _Value);

	UFUNCTION(BlueprintCallable)
	void StopMoving()
	{
		CurAnimation = EPlayerState::IDLE;
	}

	UFUNCTION(BlueprintCallable)
	void CheckOverlap(AActor* Actor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	EPlayerState CurAnimation = EPlayerState::IDLE;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//class UInputAction* MoveAction = nullptr;
};
