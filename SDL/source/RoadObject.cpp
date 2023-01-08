#include "RoadObject.h"

RoadObject::RoadObject(int _carID, int _speed): carID(_carID), speed(_speed)
{
	switch (carID)
	{
	case 0:
		path = "../resources/Truck.png";
		break;
	case 1:
		path = "../resources/Car1.png";
		break;
	case 2:
		path = "../resources/Car2.png";
		break;
	case 3:
		path = "../resources/Car3.png";
		break;
	case 4:
		path = "../resources/Car4.png";
		break;
	}
	renderers.push_back(new ImageRenderer());
}

void RoadObject::Load()
{
	renderers[0]->Load(path);
}

void RoadObject::Update()
{
}

void RoadObject::Render()
{
}
