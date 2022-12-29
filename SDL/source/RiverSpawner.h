#pragma once
#include "Spawner.h"
#include "RiverObject.h"

class RiverSpawner :
    public Spawner
{
private:
    float minLength;
    float maxLength;
    float length = 0;

    ROTYPE type;

public:
    RiverSpawner(ROTYPE type, float maxT, float minT, float e, float startV, float minL, float maxL, Vector2 startP, float cChance, float sChance)
        : Spawner(maxT, minT, e, startV, startP), type(type), minLength(minL), maxLength(maxL) {}
    
    void Update(float dt) override;
};

