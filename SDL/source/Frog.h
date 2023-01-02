#pragma once
#include "Vector2.h"
#include "Food.h"
#include "GameObject.h"


class Frog:public GameObject
{
private:
	Vector2 targetPosition;
	bool moving = false;
	bool hasFood=false;
	Food* food;

public:
	Frog();
	virtual void Update()override;
	virtual void Render()override;

};

