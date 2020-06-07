// Fill out your copyright notice in the Description page of Project Settings.


#include "Ring.h"

// Sets default values
ARing::ARing() :
	Score(15)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Niagara = CreateDefaultSubobject<UNiagaraSystem>(TEXT("Niagara"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RingVisualAsset(TEXT("/Game/Geometry/Ring.Ring"));

	if (RingVisualAsset.Succeeded()) {
		Mesh->SetStaticMesh(RingVisualAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Mesh->SetCollisionProfileName(TEXT("Trigger"));
		Mesh->SetSimulatePhysics(false);
	}
}

// Called when the game starts or when spawned
void ARing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

