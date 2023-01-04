#include "LogSpawner.h"

GameObject* LogSpawner::Spawn()
{
	GameObject* gO;
	float length = (rand() % (int)maxSpawnTime) - minSpawnTime;

	int randomNum = rand() % 100;

	if (randomNum < crocChance) 
	{
		gO=new Crocodile(length, 0);//ns que es el second chance
	}
	else if(randomNum>crocChance&&randomNum<(crocChance+snakeChance))
	{
		auto log = new Log(length, 0);
		gO=new Snake(log);
	}
	else
	{
		gO=new Log(length, 0);//ns k es secondchance
	}
	return gO;
}
