#pragma once
#include "Vector2.h"
#include "GameplayScene.h"
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

	GameplayScene* scene;

	virtual void Spawn() = 0;

public:
	Spawner(float maxT, float minT, float startV, Vector2 startP, GameplayScene* scene)
		: maxSpawnTime(maxT), minSpawnTime(minT), startVelocity(startV), startPosition(startP), scene(scene) {}

	virtual void Update(float dt) = 0;
};

