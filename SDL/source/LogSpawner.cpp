#include "LogSpawner.h"

std::random_device rd;
std::mt19937 gen(rd());

void LogSpawner::Spawn(GameplayScene* Game)
{
	std::uniform_int_distribution<> dist(minLength, maxLength);
	float length = dist(gen);

	int randomNum = rand() % 100;

	if (randomNum < crocChance) 
	{
		Game->AddGameObject(new Crocodile(length, 0));//ns que es el second chance
	}
	else if(randomNum>crocChance&&randomNum<(crocChance+snakeChance))
	{
		GameObject* log = new Log(length, 0);
		Game->AddGameObject(log);//ns k es secondchance
		GameObject* snake = new Snake(log);
		Game->AddGameObject(snake);
	}
	else
	{
		//Spawn log
	}
}
