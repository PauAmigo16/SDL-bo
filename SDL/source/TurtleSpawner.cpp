#include "TurtleSpawner.h"

GameObject* TurtleSpawner::Spawn()
{
	GameObject* gO=nullptr;
	float length = (rand() % (int)maxLength) - minLength;

	int randomNum = rand() % 100;

	if (randomNum < diveChance) 
	{
		gO = new DivingTurtles(1.0f, 3.0f, length);
	}
	else {
		gO = new Turtle(length);
	}
	return gO;
}
