#include "LogSpawner.h"

std::random_device rd;
std::mt19937 gen(rd());

void LogSpawner::Spawn()
{
	std::uniform_int_distribution<> dist(minLength, maxLength);
	float length = dist(gen);

	int randomNum = rand() % 100;

	if (randomNum < crocChance) 
	{
		//Spawn crocodile
	}
	else if(randomNum>crocChance&&randomNum<(crocChance+snakeChance))
	{
		//Spawn snake
	}
	else
	{
		//Spawn log
	}
}
