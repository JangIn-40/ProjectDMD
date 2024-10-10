// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SKMeshAsset(
		TEXT("SkeletalMesh'/Game/Assets/Fantasy_Pack/Characters/Barbarian/Mesh/SK_Barbarian_Full.SK_Barbarian_Full'")
	);
	if (SKMeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SKMeshAsset.Object);
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
		GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("SKMesh Load Fail"));
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> IdleAnimationAsset(
		TEXT("AnimSequence'/Game/Assets/Fantasy_Pack/Animations/1With_Weapon/Anim_Warrior_Idle.Anim_Warrior_Idle'")
	);
	if (IdleAnimationAsset.Succeeded())
	{
		IdleAnimation = IdleAnimationAsset.Object;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("IdleAnimation Load Fail"));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(GetMesh());
	SpringArm->TargetArmLength = 1600.f;
	SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->bDoCollisionTest = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (!Camera)
	{
		UE_LOG(LogTemp, Log, TEXT("why isn't work?"));
	}
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
}

void APlayerCharacter::BeginPlay()
{
}
