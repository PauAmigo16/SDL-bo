#pragma once
#include "Spawner.h"
#include "Log.h"
#include "Crocodile.h"
#include "Snake.h"

class LogSpawner :
	public Spawner
{
private:
	float crocChance;
	float snakeChance;
	float minLength;
	float maxLength;

	GameObject* Spawn() override;

public:
	LogSpawner(float minL, float maxL, float minT, float maxT, float crocChance, float snakeChance, float startV, Vector2 startP)
		: Spawner(maxT, minT, startV, startP), crocChance(crocChance), snakeChance(snakeChance), minLength(minL), maxLength(maxL) {}

	GameObject* Update(float dt) override;
};

