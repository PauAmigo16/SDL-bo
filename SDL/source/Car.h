#pragma once
#include "GameObject.h"
#include "ImageRenderer.h"

enum class CarType { TRUCK, CAR1, CAR2, CAR3, CAR4 };

class Car :
	public GameObject
{
private:
	std::string path;
public:
	Car(CarType	type);

	void Load() override;
	void Update() override;
	void Render() override;
};

