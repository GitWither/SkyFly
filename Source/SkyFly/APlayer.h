// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "APlayer.generated.h"

UCLASS()
class SKYFLY_API AAPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAPlayer();

	UPROPERTY(EditAnywhere, Category = "Thruster")
	float ThrustForce;

	UPROPERTY(EditAnywhere, Category = "Score")
	int CurrentScore;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
		void HorizontalRot(float value);

	UFUNCTION()
		void VerticalRot(float vlaue);

	UFUNCTION()
		void AddScore(int score);

	UFUNCTION()
		void TestScore();

	UFUNCTION()
		void AddThrust(float force);
};
