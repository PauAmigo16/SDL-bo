#pragma once
#include "Spawner.h"
#include "Turtle.h"
#include "DivingTurtles.h"

class TurtleSpawner :
    public Spawner
{
private:
    float diveChance;
    float minLength;
    float maxLength;

    GameObject* Spawn() override;

public:
    TurtleSpawner(float minL, float maxL, float minT, float maxT, float diveChance, float startV, Vector2 startP)
        : Spawner(maxT, minT, startV, startP), diveChance(diveChance), maxLength(maxL), minLength(minL){}
};

