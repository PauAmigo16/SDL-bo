#pragma once
#include "Turtles.h"

class DivingTurtles :
    public Turtles
{
private:
    float diveDuration;
    float surfaceDuration;
    float elapsedTime;

    bool isDiving;

    std::string path;

public:
    DivingTurtles(float diveDuration, float surfaceDuration, int length) :Turtles(length), diveDuration(diveDuration), surfaceDuration(surfaceDuration)
    {
        path = "../resources/DivingTurtleAnimation.png";
    }

    void Update() override;
    void Render() override;

    bool IsDiving();
};

