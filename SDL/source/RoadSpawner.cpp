#include "RoadSpawner.h"

GameObject* RoadSpawner::Spawn()
{
	GameObject* gO=nullptr;

	gO = new RoadObject(carId, startVelocity);

	eTime = 0.0f;

	return gO;
}