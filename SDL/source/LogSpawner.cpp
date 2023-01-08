#include "LogSpawner.h"

GameObject* LogSpawner::Spawn()
{
	GameObject* gO;
	float length = (rand() % (int)maxSpawnTime) - minSpawnTime;

	int randomNum = rand() % 100;

	if (randomNum < crocChance)
	{
		gO = new Crocodile(1.0f, 3.0f, length, startPosition.y);//ns que es el second chance
	}
	else if (randomNum > crocChance && randomNum < (crocChance + snakeChance))
	{
		auto log = new Log(length, startPosition.y);
		gO = new Snake(log);
	}
	else
	{
		gO = new Log(length, startPosition.y);//ns k es secondchance
	}
	return gO;
}
