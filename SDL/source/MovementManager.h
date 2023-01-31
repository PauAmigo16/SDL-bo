#pragma once
#include "Frog.h"
#include "InputManager.h"

#define MM MovementManager::GetInstance()

class MovementManager
{
private:
	static MovementManager* instance;

	MovementManager() = default;

public:

	static MovementManager* GetInstance();

	void MoveFrog(Frog* frog, Direction direction);
};

