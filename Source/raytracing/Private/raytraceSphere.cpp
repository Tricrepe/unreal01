// Fill out your copyright notice in the Description page of Project Settings.


#include "raytraceSphere.h"

#include "VectorTypes.h"
// Sets default values
AraytraceSphere::AraytraceSphere()
{
}

// Called when the game starts or when spawned
void AraytraceSphere::BeginPlay()
{
	Super::BeginPlay();
	rayOrigin = {3.f,0.f,0.f};
	float length = 100.f;
	float radius = 5.f;
	
	width=12;
	height=12;
	UWorld* world = GetWorld();
	
	for (uint8 y=0;y<height;y++)
	{
		for (uint8 x=0;x<width;x++)
		{
			FVector2D coord = {(float)x/(float)width,(float)y/(float)height};
			rayDirection =  {-1,coord.X,coord.Y};
			rayDirection = rayDirection.GetSafeNormal(0.001);
			
			FVector End = rayOrigin + rayDirection* length;
			
			float a = FVector::DotProduct(rayDirection,rayDirection);
			float b = 2.0f*FVector::DotProduct(rayOrigin,rayDirection);
			float c = FVector::DotProduct(rayOrigin,rayOrigin)-radius*radius;
			float discriminant = b*b-4.f*a*c;
			if (discriminant>=0)
			{
				DrawDebugLine(world, rayOrigin, End,{255,0,255},true,50.f, 0, 0.5f);
				{
					DrawDebugLine(world, rayOrigin, End,{0,255,0},true,50.f, 0, 0.5f);

				}
			
			}
		}
	
	
	}
}