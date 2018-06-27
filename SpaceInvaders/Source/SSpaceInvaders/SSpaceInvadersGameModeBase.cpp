// Fill out your copyright notice in the Description page of Project Settings.

#include "SSpaceInvadersGameModeBase.h"
#include "Engine/World.h"
#include "GroupAlien.h"
#include "Alien.h"
#include "Protector.h"

void ASSpaceInvadersGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnLocation = FVector(-300.0f, 0.0f, 300.0f);
	SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	TotalAiens = 40;
	Spacing = 60.0f;

	SpawnAlien();

	
}



void ASSpaceInvadersGameModeBase::SpawnAlien()
{
	auto World = GetWorld();
	if (World)
	{
		GroupAlienRef = World->SpawnActor<AGroupAlien>(GroupAlien_BP, SpawnLocation, SpawnRotation);
		for (int index = 0; index < TotalAiens; ++index)
		{
			float Horizontal = index % 10;
			float Vertical = index / 10;
			AlienRef = SpawnNewAlien(Horizontal, Vertical);
			AlienRef->SetFlipBookEvent(Vertical);
			AlienRef->AttachToActor(GroupAlienRef, FAttachmentTransformRules::KeepRelativeTransform);
		}

	}
}



AAlien * ASSpaceInvadersGameModeBase::SpawnNewAlien(float X, float Y)
{
	float DirectionX = X;
	float DirectionY = Y;

	FVector Location = FVector(DirectionX, 0.0f, DirectionY);
	FVector StratLocation = ((Location*Spacing) + SpawnLocation);

	AAlien * Alien = GetWorld()->SpawnActor<AAlien>(Alien_BP, StratLocation, SpawnRotation);
	return Alien;
}

AGroupAlien * ASSpaceInvadersGameModeBase::GetGroupAienRef()
{
	return GroupAlienRef;
}
