#include "Spawner.h"

GameObject* Spawner::Update()
{
	GameObject* gO = nullptr;

	float spawnTime = (rand() % (int)maxSpawnTime)-minSpawnTime;

	if (eTime >= spawnTime)
		gO = Spawn();

	eTime += TM->GetDt();

	return nullptr;
}
