#pragma once
#include "GameObject.h"

class RoadObject : public GameObject
{
public:
	RoadObject(std::string _carID, int _speed, int minSpawnRate, int maxSpawnRate);
	std::string carID;
	int speed,spawnRate;
};

