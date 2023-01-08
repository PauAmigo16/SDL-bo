#pragma once
#include "Turtle.h"

class DivingTurtles :
    public Turtle
{
private:
    float diveDuration;
    float surfaceDuration;
    float elapsedTime;

    bool isDiving;

    std::string path;

public:
    DivingTurtles(float diveDuration, float surfaceDuration, int length) :Turtle(length), diveDuration(diveDuration), surfaceDuration(surfaceDuration)
    {
        path = "../resources/DivingTurtleAnimation.png";
    }

    void Update() override;
    void Render() override;

    bool IsDiving();
};
