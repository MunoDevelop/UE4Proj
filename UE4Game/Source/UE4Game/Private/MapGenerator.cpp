/**
*  ? 2021 MunoDevelop <huozuyinshua@gmail.com>
*  
*/
#include "MapGenerator.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AMapGenerator::RealIdxFromTileYX(int y,int x)
{
	if (!(x<MapWidthHeight && y< MapWidthHeight)){
		return -1;
	}else
	{
		return x + MapWidthHeight * y;
	}

}

FVector AMapGenerator::WorldPosFromTileYX(int y, int x)
{
	FVector vec;
	vec.X = (x * TileScale+TileScale/2)*100;
	vec.Y = (y * TileScale+TileScale/2)*100;
	return vec;
}


// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();

	for (int y = 0;y< MapWidthHeight;y++)
	{
		for (int x = 0;x< MapWidthHeight;x++)
		{
			//FActorSpawnParameters params;
			FVector tempVec = WorldPosFromTileYX(y,x);
			tempVec.Z = TileScale*100/2;
			FRotator rotTemp = FRotator::ZeroRotator;

			AActor* act = GetWorld()->SpawnActor(TileClass,&tempVec,&rotTemp);
			Map.Add(RealIdxFromTileYX(y,x),act);
			
		}
	}
	
}

// Called every frame
void AMapGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

