#include "RoadSpawner.h"

GameObject* RoadSpawner::Spawn()
{
	GameObject* gO=nullptr;

	switch (carId)
	{
	case 0:
		//Spawn truck
		break;
	case 1:
		//Spawn racing 1
		break;
	case 2:
		//Spawn racing 2
		break;
	case 3:
		//Spawn farming
		break; 
	case 4:
		//Spawn family
		break;
	}

	return gO;
}
