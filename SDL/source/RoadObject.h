#pragma once
#include "GameObject.h"

class RoadObject : public GameObject
{
public:
	RoadObject(std::string _carID, int _speed);
	std::string carID;
	int speed;
};

