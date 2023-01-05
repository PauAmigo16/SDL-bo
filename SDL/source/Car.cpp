#include "Car.h"

Car::Car(CarType type)
{
	switch (type)
	{
	case CarType::TRUCK:
		path = "../resources/Truck.png";
		break;
	case CarType::CAR1:
		path = "../resources/Car1.png";
		break;
	case CarType::CAR2:
		path = "../resources/Car2.png";
		break;
	case CarType::CAR3:
		path = "../resources/Car3.png";
		break;
	case CarType::CAR4:
		path = "../resources/Car4.png";
		break;
	}
	renderers.push_back(ImageRenderer());
}

void Car::Load()
{
		renderers[0].Load(path);
}
