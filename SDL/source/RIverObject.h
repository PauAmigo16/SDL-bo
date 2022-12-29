#pragma once
#include "GameObject.h"

enum class ROTYPE { TURTLE, LOG };

class RiverObject : public GameObject
{
public:
	RiverObject(int _minLenght, int _maxLenght, int _minSpawnRate, int _maxSpawnRate, int _crocodileChance, int _secondChance); //trconcs
	RiverObject(int _minLenght, int _maxLenght, int _minSpawnRate, int _maxSpawnRate, int _secondChance); //Tortugues

	ROTYPE type;

	int lenght,secondChance, spawnRate;
	int  crocodileChance = 0;
};

