#pragma once
#include "Vector2.h"
#include "GameObject.h"
#include "TimeManager.h"
#include <random>

class Spawner
{
protected:
	float maxSpawnTime;
	float minSpawnTime;
	float eTime;
	float startVelocity;

	Vector2 startPosition;

	virtual GameObject* Spawn() = 0;

public:
	Spawner(float maxT, float minT, float startV, Vector2 startP)
		: maxSpawnTime(maxT), minSpawnTime(minT), startVelocity(startV), startPosition(startP) {}

	virtual GameObject* Update(float dt) = 0;
};

