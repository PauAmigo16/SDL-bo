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
	switch (direction)
	{
	case Direction::UP:
		frog->AddMovement(Vector2(0, -1));
		break;
	case Direction::DOWN:
		frog->AddMovement(Vector2(0, 1));
		break;
	case Direction::LEFT:
		frog->AddMovement(Vector2(-1, 0));
		break;
	case Direction::RIGHT:
		frog->AddMovement(Vector2(1, 0));
		break;
	default:
		break;
	}
}
