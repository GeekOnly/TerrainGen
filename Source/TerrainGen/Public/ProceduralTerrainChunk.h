// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProceduralMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralTerrainChunk.generated.h"

UCLASS()
class TERRAINGEN_API AProceduralTerrainChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralTerrainChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostActorCreated() override;
	
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* procMesh;

	UPROPERTY(EditAnywhere)
	float heightScale = 100.0f;

	UPROPERTY(EditAnywhere)
	float widthScale = 10.0f;

public:
	int Seed = 1337;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	void CreateRandomMeshComponent();

	int SetSizeAndResolution(float size, int resolution);
	void SetXandYStart(int xStart, int yStart);
	void SetMaterialForProcMesh(UMaterialInterface* material);

private:
	int heightMapLength = 100;
	int xStart = 0;
	int yStart = 0;
	TArray<TArray<float>> generateHeightmap(int width, int height);
	TArray<FVector> generateVertices(TArray<TArray<float>> heightmap);
	TArray<FVector> generateNormals(TArray<FVector> verts, TArray<TArray<float>> hMap, int width, int height);
	TArray<int32> generateTriangles(int32 width, int32 height);
	TArray<FVector2D> generateUV(int width, int height);
};
