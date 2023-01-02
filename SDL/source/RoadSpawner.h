#pragma once
#include "Spawner.h"
#include "RoadObject.h"

class RoadSpawner :
    public Spawner
{
private:
    int carId;

    void Spawn() override;

public:
    RoadSpawner(float maxT, float minT, float startV, Vector2 startP, GameplayScene* scene, int carId)
        : Spawner(maxT, minT, startV, startP, scene), carId(carId) {}

    void Update(float dt) override;
};

