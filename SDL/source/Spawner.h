#pragma once
#include "Vector2.h"
#include "GameplayScene.h"

class Spawner
{
protected:
	float maxSpawnTime;
	float minSpawnTime;
	float eTime;
	float startVelocity;

	Vector2 startPosition;

public:
	Spawner(float maxT, float minT, float e, float startV, Vector2 startP)
		: maxSpawnTime(maxT), minSpawnTime(minT), eTime(e), startVelocity(startV), startPosition(startP) {}

	virtual void Update(float dt) = 0;
};

