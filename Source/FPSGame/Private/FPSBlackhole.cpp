// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSBlackhole.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFPSBlackhole::AFPSBlackhole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiate component TEXT : give name 
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(100);
	SphereComp->SetupAttachment(MeshComp);

	GravityEffect = CreateDefaultSubobject<USphereComponent>(TEXT("GravityEffect"));
	GravityEffect->SetSphereRadius(3000);
	GravityEffect->SetupAttachment(MeshComp);
	//GravityEffect->AddForce();
	//GravityEffect->AddRadialForce();
	

}

// Called when the game starts or when spawned
void AFPSBlackhole::BeginPlay()
{
	Super::BeginPlay();
	//SphereComp->GetOverlappingComponents();
	
}

// Called every frame
void AFPSBlackhole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

