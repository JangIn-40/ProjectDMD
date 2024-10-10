// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDMDPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"

AProjectDMDPlayerController::AProjectDMDPlayerController()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> PlayerMappingContextAsset(
		TEXT("InputMappingContext'/Game/Input/IMC_Player.IMC_Player'")
	);
	if (PlayerMappingContextAsset.Succeeded())
	{
		PlayerMappingContext = PlayerMappingContextAsset.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("PlayerMappingContext Load Fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionAsset(
		TEXT("InputAction'/Game/Input/Actions/IA_Move.IA_Move'")
	);
	if (MoveActionAsset.Succeeded())
	{
		MoveAction = MoveActionAsset.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("MoveAction Load Fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> DashActionAsset(
		TEXT("InputAction'/Game/Input/Actions/IA_Dash.IA_Dash'")
	);
	if (DashActionAsset.Succeeded())
	{
		DashAction = DashActionAsset.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("DashAction Load Fail"));
	}
}

void AProjectDMDPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectDMDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Setting Enhanced Input System
	UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubSystem =
		GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	LocalPlayerSubSystem->AddMappingContext(PlayerMappingContext, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered,
			this, &AProjectDMDPlayerController::Move);
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started,
			this, &AProjectDMDPlayerController::Dash);
}

void AProjectDMDPlayerController::Move(const FInputActionValue& Value)
{
	FVector2D AxisValue = Value.Get<FVector2D>();
}

void AProjectDMDPlayerController::Dash(const FInputActionValue& Value)
{
	bool IsPressed = Value.Get<bool>();

	if (IsPressed)
	{
		
	}
}
