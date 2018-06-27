// Fill out your copyright notice in the Description page of Project Settings.

#include "GroupAlien.h"
#include "Engine/World.h"
#include "GeneratedCodeHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Alien.h"
#include "TimerManager.h"

// Sets default values
AGroupAlien::AGroupAlien()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGroupAlien::BeginPlay()
{
	Super::BeginPlay();
	
	MoveDirection = 1.0f;
	FTimerHandle TimeHandle;

	GetWorldTimerManager().SetTimer(TimeHandle, this, &AGroupAlien::SpawnRandomProjectile, 2.0f, true, 0.5f);
}

// Called every frame
void AGroupAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveSideWays();
}

void AGroupAlien::MoveSideWays()
{
	FVector MoveLocation = FVector(300.0f, 0.0f, 0.0f);
	auto Time = GetWorld()->DeltaTimeSeconds;
	auto Transform = GetActorTransform();
	Transform.AddToTranslation(MoveDirection*MoveLocation*Time);
	SetActorRelativeTransform(Transform);
}

void AGroupAlien::MoveDown()
{
	FVector MoveLocation = FVector(0.0f, 0.0f, -1500.0f);
	auto Time = GetWorld()->DeltaTimeSeconds;
	auto Transform = GetActorTransform();
	Transform.AddToTranslation(MoveLocation*Time);
	SetActorRelativeTransform(Transform);

}



void AGroupAlien::SpawnRandomProjectile()
{
	//Get all the actors of class AAlien and store them to an array
	UGameplayStatics::GetAllActorsOfClass(this, AAlien::StaticClass(), FoundActors);
	
	int32 Min = 1;
	int32 Max = 5;
	auto Range = FMath::RandRange(Min, Max);
	AAlien*Alien = nullptr;
	FCustomThunkTemplates::Array_Shuffle(FoundActors);
	FoundActors.SetNum(Range, true);
	for (AActor*Actor : FoundActors)
	{
		Alien = Cast<AAlien>(Actor);
		if (Alien)
		{
			Alien->DropProjectile();
			
		}
		else
		{
			return;
		}
		
	}
	
	FoundActors.Remove(Alien);
	

}
	//

	


