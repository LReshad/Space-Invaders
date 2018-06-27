// Fill out your copyright notice in the Description page of Project Settings.

#include "AlienProjectile.h"
#include "PaperFlipbookComponent.h"


// Sets default values
AAlienProjectile::AAlienProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Projectile = CreateDefaultSubobject<UPaperFlipbookComponent>(FName("Projectile"));
	RootComponent = Projectile;
}

// Called when the game starts or when spawned
void AAlienProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlienProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TODO projectile speed
	auto Transform = Projectile->GetRelativeTransform();
	Transform.AddToTranslation(FVector(0.0f, 0.0f, -80.0f)*DeltaTime*10.0f);
	Projectile->SetRelativeTransform(Transform, true);
}

