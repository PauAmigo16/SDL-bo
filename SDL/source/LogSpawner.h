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

	void Spawn(GameplayScene* Game) override;

public:
	LogSpawner(float maxT, float minT, float startV, Vector2 startP, GameplayScene* scene, float crocChance, float snakeChance, float minL, float maxL)
		: Spawner(maxT, minT, startV, startP, scene), crocChance(crocChance), snakeChance(snakeChance), minLength(minL), maxLength(maxL) {}

	void Update(float dt) override;
};

