// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRandLow;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRandHigh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UBoxComponent* GetwhereToSpawn() const { return WhereToSpawn; }

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	UFUNCTION(BlueprintCallable, Category ="Spawning")
	void SetSpawningActive(bool bShouldSpawn);
private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))

	class UBoxComponent* WhereToSpawn;
	
	void SpawnPickup();

	float SpawnDelay;
};