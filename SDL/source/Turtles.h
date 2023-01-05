#pragma once
#include "GameObject.h"

class Turtles :
	public GameObject
{
private:
	int length;

	std::string path;

public:
	Turtles(int length);

	virtual void Load() override;
	virtual void Update() override;
	virtual void Render() override;
};

