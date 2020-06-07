// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayer.h"

// Sets default values
AAPlayer::AAPlayer() :
	ThrustForce(25.f),
	CurrentScore(0.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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

	PlayerInputComponent->BindAxis("MouseHorizontal", this, &AAPlayer::HorizontalRot);
	PlayerInputComponent->BindAxis("MouseVertical", this, &AAPlayer::VerticalRot);
	//PlayerInputComponent->BindKey(EKeys::F, IE_Pressed, this, &AAPlayer::TestScore);
}

void AAPlayer::AddThrust(float force) {
	UPrimitiveComponent* charMovement = (UPrimitiveComponent*)GetCharacterMovement();
	charMovement->AddForce(GetActorForwardVector() * force);
}

void AAPlayer::HorizontalRot(float value) {
	AddControllerPitchInput(value);
}

void AAPlayer::VerticalRot(float value) {
	AddControllerYawInput(value);
}

void AAPlayer::AddScore(int score) {
	AAPlayer::CurrentScore += score;
}

void AAPlayer::TestScore() {
	AAPlayer::CurrentScore += 25;
}