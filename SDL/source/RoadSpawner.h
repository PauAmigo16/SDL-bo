#pragma once
#include "Spawner.h"
#include "RoadObject.h"
#include "TimeManager.h"

class RoadSpawner :
    public Spawner
{
private:
    int carId;

    GameObject* Spawn() override;

public:
    RoadSpawner(int carId, float maxT, float minT, float startV, Vector2 startP)
        : Spawner(maxT, minT, startV, startP), carId(carId) {}
};

