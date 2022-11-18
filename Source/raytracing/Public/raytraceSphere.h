// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "raytraceSphere.generated.h"

UCLASS()
class RAYTRACING_API AraytraceSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AraytraceSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	FVector rayOrigin;
	FVector rayDirection;
	
	uint8 width;
	uint8 height;
	
};
