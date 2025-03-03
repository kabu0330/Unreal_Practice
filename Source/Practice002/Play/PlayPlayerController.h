// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"

#include "PlayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE002_API APlayPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APlayPlayerController();

	UFUNCTION(BlueprintCallable)
	void AddMappingContext(UInputMappingContext* MappingContext);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float _DeltaTime) override;

	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* InputMappingContext = nullptr;
};

