#pragma once
#include "Spawner.h"
class TurtleSpawner :
    public Spawner
{
private:
    float diveChance;
    float minLength;
    float maxLength;

    void Spawn() override;

public:
    TurtleSpawner(float maxT, float minT, float startV, Vector2 startP, GameplayScene* scene, float diveChance, float minL, float maxL)
        : Spawner(maxT, minT, startV, startP, scene), diveChance(diveChance), maxLength(maxL), minLength(minL){}

    void Update(float dt) override;
};

