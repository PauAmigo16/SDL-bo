#pragma once
#include "GameObject.h"
#include "Food.h"

class Frog :
    public GameObject
{
private:
    Vector2 position;
    Vector2 targetPos;

    bool moving;
    bool hasFood;

    Food* food;

    std::string path;

public:
    Frog();

    void Respawn();
    void AddMovement(Vector2 dir);
    void Load();
    void Update() override;
    void Render() override;
    void AddFood(Food* food);

    bool isMoving();
};

