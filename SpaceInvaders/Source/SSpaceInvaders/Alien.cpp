// Fill out your copyright notice in the Description page of Project Settings.

#include "Alien.h"
#include "PaperFlipbookComponent.h"


// Sets default values
AAlien::AAlien()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Alien = CreateDefaultSubobject<UPaperFlipbookComponent>(FName("Alien"));
	RootComponent = Alien;
}

// Called when the game starts or when spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

