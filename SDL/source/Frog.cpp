#include "Frog.h"
#include "Frog.h"
#include "Frog.h"

Frog::Frog()
{
    path = "../resources/FrogAnimation.png";
    renderers.push_back(new AnimatedImageRenderer());
}

void Frog::Update()
{
    if (position != nextPos)
        Move();
    else
        moving = false;
}

void Frog::Render()
{
    renderers[0]->Render();
}

void Frog::Respawn()
{
}

void Frog::Move()
{
    moving = true;

    switch (direction)
    {
    case Direction::UP:
        position.y -= 1;
        break;
    case Direction::DOWN:
        position.y += 1;
        break;
    case Direction::LEFT:
        position.x -= 1;
        break;
    case Direction::RIGHT:
        position.x += 1;
        break;
    }
}

void Frog::AddDirection(Direction direct)
{
    direction = direct;

    switch (direction)
    {
    case Direction::UP:
        nextPos.y = position.y - 16;
        break;
    case Direction::DOWN:
        nextPos.y = position.y + 16;
        break;
    case Direction::LEFT:
        nextPos.x = position.x - 16;
        break;
    case Direction::RIGHT:
        nextPos.x = position.x - 16;
        break;
    }
}

void Frog::Load()
{
    renderers[0]->Load(path);
}

void Frog::AddFood(Food* food)
{
    this->food = food;
}

bool Frog::isMoving()
{
    return moving;
}
