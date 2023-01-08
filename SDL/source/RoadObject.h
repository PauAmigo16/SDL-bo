#pragma once
#include "GameObject.h"

class RoadObject : public GameObject
{
public:
	int carID;
	int speed,spawnRate;
	
	std::string path;

	RoadObject(int _carID, int _speed);

	virtual void Load() override;
	virtual void Update() override;
	virtual void Render() override;
};

