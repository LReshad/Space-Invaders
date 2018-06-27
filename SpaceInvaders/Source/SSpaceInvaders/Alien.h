// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Alien.generated.h"

UCLASS()
class SSPACEINVADERS_API AAlien : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "AleinFlipBook")
	class UPaperFlipbookComponent * Alien = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category = "SetFlipbook")
	void SetFlipBookEvent(int32 Index);

	UFUNCTION(BlueprintImplementableEvent, Category = "SpawnProjectile")
	void DropProjectile();
	
};
