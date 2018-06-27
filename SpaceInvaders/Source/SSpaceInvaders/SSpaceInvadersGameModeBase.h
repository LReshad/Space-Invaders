// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SSpaceInvadersGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SSPACEINVADERS_API ASSpaceInvadersGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AGroupAlien>GroupAlien_BP;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AAlien>Alien_BP;




	AGroupAlien * GroupAlienRef = nullptr;

	AAlien * AlienRef = nullptr;

	FVector  SpawnLocation;
	FRotator  SpawnRotation;
	int32 TotalAiens;
	float Spacing;

	void SpawnAlien();

	void SpawnProtector();

	AAlien* SpawnNewAlien(float X, float Y);

	UFUNCTION(BlueprintCallable,Category="Getter")
	AGroupAlien * GetGroupAienRef();


	
};
