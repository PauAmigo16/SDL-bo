#include "TurtleSpawner.h"

std::random_device rd;
std::mt19937 gen(rd());

void TurtleSpawner::Spawn()
{
	std::uniform_int_distribution<> dist(minLength, maxLength);
	float length = dist(gen);

	int randomNum = rand() % 100;

	if (randomNum < diveChance) 
	{
		//spawn Diving Turtle
	}
	else {
		//spawn turtle
	}
}