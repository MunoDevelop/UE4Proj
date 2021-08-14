/**
*  ? 2021 MunoDevelop <huozuyinshua@gmail.com>
*  
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"


#include "MapGenerator.generated.h"

UCLASS()
class UE4GAME_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MapWidthHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TileScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ATile> TileClass;

	
	//map
	TMap<int32,AActor*> Map;
	
	int RealIdxFromTileYX(int y,int x);

	FVector WorldPosFromTileYX(int y,int x);

	void MapGenerateAnimation();
	// Sets default values for this actor's properties
	AMapGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
