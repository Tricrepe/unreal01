#include "learningBox.h"

AlearningBox::AlearningBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Cubemesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Cubemesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		Cubemesh->SetStaticMesh(CubeVisualAsset.Object);
		Cubemesh->SetRelativeLocation(FVector(0.f,0.f,0.f));
	}

}

void AlearningBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AlearningBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector newLocation = GetActorLocation();
	FRotator newRotation = GetActorRotation();
	float Runningtime = GetGameTimeSinceCreation();
	float deltaHeight = FMath::Sin(Runningtime+DeltaTime)-FMath::Sin(Runningtime);
	float deltaRotation = DeltaTime*20.f;
	newLocation.Z += deltaHeight*20.f;
	newRotation.Yaw += deltaRotation;
	
	SetActorLocationAndRotation(newLocation,newRotation);
}

