#include "MovementManager.h"

MovementManager* MovementManager::instance = nullptr;

MovementManager* MovementManager::GetInstance()
{
    if (instance == nullptr)
        instance = new MovementManager();
    return instance;
}

void MovementManager::MoveFrog(Frog* frog, Direction direction)
{
    frog->AddDirection(direction);
}
