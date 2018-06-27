// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

UCLASS()
class SSPACEINVADERS_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, Category= "ShipFipBook")
	class UPaperFlipbookComponent * Ship = nullptr;

	void Move(float AxisValue);

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AShipProjectile>ShipProjectile_BP;



	void SpawnProjectile();

	UFUNCTION(BlueprintImplementableEvent, Category = "Playsound")
	void PlaySound();


	///These Variables are use to make a fire cooldown method
	float FireReady;
	float CoolDownTime;
	
	
};
