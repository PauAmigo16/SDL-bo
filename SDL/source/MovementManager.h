#pragma once
#include "Frog.h"
#include "InputManager.h"

class MovementManager
{
private:
	static MovementManager* instance;

	MovementManager();

public:

	static MovementManager* GetInstance();

	void MoveFrog(Frog* frog, Direction direction);
};

