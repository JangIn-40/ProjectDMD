// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectDMDGameMode.h"
#include "PlayerCharacter.h"
#include "ProjectDMDPlayerController.h"

AProjectDMDGameMode::AProjectDMDGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = AProjectDMDPlayerController::StaticClass();
}
