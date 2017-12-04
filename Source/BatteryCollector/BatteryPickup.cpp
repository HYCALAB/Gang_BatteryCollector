// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"

//set dafault value
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);

	BatteryPower = 150.0f;

}

void ABatteryPickup::WasCollected_Implementation()
{
	Super::WasCollected_Implementation();

	Destroy();
}

float ABatteryPickup::GetPower()
{
	return BatteryPower;
}