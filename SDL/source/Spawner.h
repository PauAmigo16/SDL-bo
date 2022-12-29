#pragma once
#include "Vector2.h"

class Spawner
{
private:
	float maxSpawnTime;
	float minSpawnTime;
	float eTime;
	float startVelocity;

	Vector2 startPosition;

public:
	Spawner(float maxTime, float minTime, float e, float startV, Vector2 startP)
		: maxSpawnTime(maxTime), minSpawnTime(minTime), eTime(e), startVelocity(startV), startPosition(startP) {}

	virtual void Update(float dt) = 0;
};

