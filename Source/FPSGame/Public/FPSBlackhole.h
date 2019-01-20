// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackhole.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class FPSGAME_API AFPSBlackhole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackhole();

protected:

	// Mesh Component
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// using spherecomponent for collision
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	// using spherecomponent for blackhole attraction
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* GravityEffect;

	// Marked with ufunction to bind to overlap events
	UFUNCTION()
	void overlapSphereComp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,  )

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
