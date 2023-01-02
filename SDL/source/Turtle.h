#pragma once
#include "GameObject.h"


class Turtle: public GameObject
{
private:
	bool Diving;
	bool Underwater;

public:
	Turtle(int _minLenght, int _maxLenght, int _secondChance);
};

