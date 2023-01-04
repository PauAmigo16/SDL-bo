#include "RoadSpawner.h"

GameObject* RoadSpawner::Spawn()
{
	GameObject* gO=nullptr;

	switch (carId)
	{
	case 0:
		gO = new RoadObject(carId, startVelocity);
		break;
	case 1:
		gO = new RoadObject(carId, startVelocity);
		break;
	case 2:
		gO = new RoadObject(carId, startVelocity);
		break;
	case 3:
		gO = new RoadObject(carId, startVelocity);
		break; 
	case 4:
		gO = new RoadObject(carId, startVelocity);
		break;
	}

	return gO;
}
