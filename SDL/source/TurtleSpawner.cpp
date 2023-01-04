#include "TurtleSpawner.h"

GameObject* TurtleSpawner::Spawn()
{
	GameObject* gO=nullptr;
	float length = (rand() % (int)maxSpawnTime) - minSpawnTime;

	int randomNum = rand() % 100;

	if (randomNum < diveChance) 
	{
		gO = new Turtle(length, 0, true);
	}
	else {
		gO = new Turtle(length, 0, false);
	}
	return gO;
}
