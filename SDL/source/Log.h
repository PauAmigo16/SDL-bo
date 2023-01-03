#pragma once
#include "GameObject.h"
#include <random>

class Log : public GameObject
{
private:
	int length;

public:
	Log(int length, int _secondChance);
	
	int tiles;

	virtual void Update() override;
	virtual void Render() override;
};

