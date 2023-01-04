#pragma once
#include "GameObject.h"

class RoadObject : public GameObject
{
public:
	int carID;
	int speed,spawnRate;

	RoadObject(int _carID, int _speed);


	virtual void Update() override;
	virtual void Render() override;
};

