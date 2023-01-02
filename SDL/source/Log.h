#pragma once
#include "GameObject.h"


class Log : public GameObject
{
public:
	Log(int _minLenght, int _maxLenght, int _crocodileChance, int _secondChance);
	int tiles;
	virtual void Update() override;
	virtual void Render() override;
};

