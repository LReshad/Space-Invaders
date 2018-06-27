// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "ShipProjectile.h"
#include "TimerManager.h"

// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(FName("RootComponet"));
	Ship = CreateDefaultSubobject<UPaperFlipbookComponent>(FName("ShipFlipbook"));
	Ship->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();

	
	CoolDownTime = 0.5f;
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move", this, &AShip::Move);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AShip::SpawnProjectile);
}

void AShip::Move(float AxisValue)
{
	AxisValue = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
	FVector Direction = FVector(10.0f, 0.0f, 0.0f);
	auto Time = GetWorld()->DeltaTimeSeconds;
	auto Transform = Ship->GetRelativeTransform();
	Transform.AddToTranslation(Direction*Time*AxisValue*50.0f);
	Ship->SetRelativeTransform(Transform, true);
}


void AShip::SpawnProjectile()
{
	auto World = GetWorld();
	auto CurrentTime = GetWorld()->GetTimeSeconds();
	if (World)
	{
		if (FireReady <= CurrentTime)
		{
			auto Location = Ship->GetSocketLocation(FName("Projectile"));
			FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
			GetWorld()->SpawnActor<AShipProjectile>(ShipProjectile_BP, Location, SpawnRotation);
			PlaySound();

			//Set the CoolDown Timer
			FireReady = CoolDownTime + CurrentTime;
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("Calling %f"), CurrentTime)
}

