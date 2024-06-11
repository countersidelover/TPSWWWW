#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pillar.generated.h"

UCLASS()
class TPSPROJECT_API APillar : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APillar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PillarMesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox; // UBoxComponent를 포함해야 합니다.
};
