#pragma once
#include "RIverObject.h"


class Turtle: public RiverObject
{
public:
	Turtle(int _minLenght, int _maxLenght, int _minSpawnRate, int _maxSpawnRate, int _secondChance):RiverObject(_minLenght, _maxLenght, _minSpawnRate, _maxSpawnRate, _secondChance) {}
};

