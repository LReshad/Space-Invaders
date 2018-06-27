// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipProjectile.h"
#include "PaperFlipbookComponent.h"

// Sets default values
AShipProjectile::AShipProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Projectile = CreateDefaultSubobject<UPaperFlipbookComponent>(FName("Projectile"));
	RootComponent = Projectile;
	
}

// Called when the game starts or when spawned
void AShipProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Transform = Projectile->GetRelativeTransform();
	Transform.AddToTranslation(FVector(0.0f, 0.0f, 100.0f)*DeltaTime*10.0f);
	Projectile->SetRelativeTransform(Transform,true);


}

