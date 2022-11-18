#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "learningBox.generated.h"

UCLASS()
class RAYTRACING_API AlearningBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AlearningBox();

	UPROPERTY(EditAnywhere,Category="haha")
	UStaticMeshComponent* Cubemesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
private:
};
