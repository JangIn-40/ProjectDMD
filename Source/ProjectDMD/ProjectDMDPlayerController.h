// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "inputActionValue.h"
#include "ProjectDMDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDMD_API AProjectDMDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AProjectDMDPlayerController();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;

	void Move(const FInputActionValue& Value);
	void Dash(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputMappingContext* PlayerMappingContext;

	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(VisibleAnywhere, Category = "Input")
	UInputAction* DashAction;
};
