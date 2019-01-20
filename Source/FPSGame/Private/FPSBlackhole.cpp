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

	//bind to event
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSBlackhole::overlapSphereComp);

	GravityEffect = CreateDefaultSubobject<USphereComponent>(TEXT("GravityEffect"));
	GravityEffect->SetSphereRadius(3000);
	GravityEffect->SetupAttachment(MeshComp);
	

}

// Called when the game starts or when spawned
//void AFPSBlackhole::BeginPlay()
//{
//	Super::BeginPlay();
	//SphereComp->GetOverlappingComponents();
	
//}

void AFPSBlackhole::overlapSphereComp(UPrimitiveComponent * OverlappedComponent, 
	AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}

// Called every frame
void AFPSBlackhole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// find all overlapping components that can collid and may be physically simulating
	TArray<UPrimitiveComponent*> OverlappingComps;
	GravityEffect->GetOverlappingComponents(OverlappingComps);
	
	for (int32 i = 0; i < OverlappingComps.Num(); i++)
	{
		UPrimitiveComponent* PrimComp = OverlappingComps[i];
		if (PrimComp && PrimComp->IsSimulatingPhysics())
		{
			// the component we are looking for, it needs to be simulating in order to apply force

			const float SphereRadius = GravityEffect->GetScaledSphereRadius();
			const float ForceStrength = -2000; // Negative value to pull towards the origin instead of pushing away

			PrimComp->AddRadialForce(GetActorLocation(), SphereRadius, ForceStrength, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}


}

