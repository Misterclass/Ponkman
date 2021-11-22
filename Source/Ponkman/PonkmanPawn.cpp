// Fill out your copyright notice in the Description page of Project Settings.


#include "PonkmanPawn.h"
#include "Foodie.h"

// Sets default values
APonkmanPawn::APonkmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APonkmanPawn::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APonkmanPawn::OnOverlapBegin);
}

// Called every frame
void APonkmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Frozen)
	{
		AddMovementInput(GetActorForwardVector());
	}
}

// Called to bind functionality to input
void APonkmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APonkmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) SetActorRotation(FRotator(0, 270, 0));
	else if (Direction == FVector::DownVector) SetActorRotation(FRotator(0, 90, 0));
	else if (Direction == FVector::RightVector) SetActorRotation(FRotator(0, 0, 0));
	else if (Direction == FVector::LeftVector) SetActorRotation(FRotator(0, 180, 0));
}


void APonkmanPawn::OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor)
{
	//TODO: interface call!
	if (OtherActor->ActorHasTag("Foodie.Regular"))
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}

	if (OtherActor->ActorHasTag("Foodie.PowerUp"))
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}
}

