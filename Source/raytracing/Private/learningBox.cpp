#include "learningBox.h"

AlearningBox::AlearningBox()
{
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	VisualMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeVisualAsset.Object)
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.f,0.f,0.f));
	}

	Cubemesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Acube"));
	Cubemesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (CubeAsset.Object)
	{
		Cubemesh->SetStaticMesh(CubeAsset.Object);
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
}

