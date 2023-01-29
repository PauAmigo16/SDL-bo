#pragma once
#include "GameObject.h"
#include "Food.h"

class Frog :
    public GameObject
{
private:
    Vector2 position;
    Vector2 targetPos;
    Vector2 nextPos;

    Direction direction;

    bool moving;
    bool hasFood;
    int score;

    Food* food;

    std::string path;

    void Respawn();
    void Move();

public:
    Frog();

    void AddDirection(Direction direct);
    void Load();
    void Update() override;
    void Render() override;
    void AddFood(Food* food);

    bool isMoving();
};

