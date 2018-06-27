// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GroupAlien.generated.h"

UCLASS()
class SSPACEINVADERS_API AGroupAlien : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGroupAlien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category="Direction")
	float MoveDirection;

	void MoveSideWays();

	UFUNCTION(BlueprintCallable,Category = "MoveDown")
	void MoveDown();

	//To Get the BP reference from alien class
	UPROPERTY(EditAnywhere, Category = "FindClass")
	TSubclassOf<class AAlien>ClassToFind;

	//To Store all the actors of the alien class
	TArray<AActor*>FoundActors;

	//Spawn Random Projectile
	void SpawnRandomProjectile();



	
};
