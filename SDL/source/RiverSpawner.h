#pragma once
#include "Spawner.h"

class RiverSpawner :
    public Spawner
{
public:
    RiverSpawner(float maxTime, float minTime, float e, float startV, Vector2 startP);

    void Update(float dt) override;
};

