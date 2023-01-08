#include "Frog.h"
#include "Frog.h"
#include "Frog.h"

Frog::Frog()
{
    path = "../resources/FrogAnimation.png";
    renderers.push_back(new ImageRenderer());
}

void Frog::Update()
{
}

void Frog::Render()
{
}

void Frog::Respawn()
{
}

void Frog::AddMovement(Vector2 dir)
{
    targetPos = position + dir;
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
