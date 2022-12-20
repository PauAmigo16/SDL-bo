#pragma once
#include "RIverObject.h"


class Log : public RiverObject
{
public:
	//Log(int lenght, int spawnRate, int _crocodileChance, int _secondChance); Per crear objectes a partir del original creat a levelloadercpp.
	Log(int _minLenght, int _maxLenght, int _minSpawnRate, int _maxSpawnRate, int _crocodileChance, int _secondChance):
		RiverObject(_minLenght, _maxLenght, _minSpawnRate, _maxSpawnRate, _crocodileChance, _secondChance){}
	int tiles;
};

