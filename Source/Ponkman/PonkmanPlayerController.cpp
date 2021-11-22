// Fill out your copyright notice in the Description page of Project Settings.


#include "PonkmanPlayerController.h"

#include "PonkmanPawn.h"

void APonkmanPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APonkmanPlayerController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APonkmanPlayerController::MoveDown);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APonkmanPlayerController::MoveRight);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APonkmanPlayerController::MoveLeft);
}

APonkmanPawn* APonkmanPlayerController::GetPonkmanPawn() const
{
	return Cast<APonkmanPawn>(GetPawn());
}

void APonkmanPlayerController::MoveUp()
{
	if (GetPonkmanPawn() != nullptr)
	{
		GetPonkmanPawn()->SetDirection(FVector::UpVector);
	}
}

void APonkmanPlayerController::MoveDown()
{
	if (GetPonkmanPawn() != nullptr)
	{
		GetPonkmanPawn()->SetDirection(FVector::DownVector);
	}
}

void APonkmanPlayerController::MoveRight()
{
	if (GetPonkmanPawn() != nullptr)
	{
		GetPonkmanPawn()->SetDirection(FVector::RightVector);
	}
}

void APonkmanPlayerController::MoveLeft()
{
	if (GetPonkmanPawn() != nullptr)
	{
		GetPonkmanPawn()->SetDirection(FVector::LeftVector);
	}
}