#pragma once
#include "GameObject.h"

class RoadObject : public GameObject
{
public:
	RoadObject(int _carID, int _speed);
	int carID;
	int speed,spawnRate;

	virtual void Update() override;
	virtual void Render() override;
};

