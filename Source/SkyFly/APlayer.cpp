// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"

// Sets default values
AAPlayer::AAPlayer() :
	ThrustForce(25.f),
	CurrentScore(0.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->GravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AAPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddThrust(AAPlayer::ThrustForce);
}

// Called to bind functionality to input
void AAPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MouseVertical", this, &APawn::AddControllerYawInput);
}

void AAPlayer::AddThrust(float force) {
	GetCharacterMovement()->AddForce(GetActorForwardVector() * force);
}

void AAPlayer::AddScore(int score) {
	AAPlayer::CurrentScore += score;
}

void AAPlayer::TestScore() {
	AAPlayer::CurrentScore += 25;
}