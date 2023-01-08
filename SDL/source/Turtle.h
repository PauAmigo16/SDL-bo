#pragma once
#include "GameObject.h"

class Turtle : public GameObject
{
private:
	int length;
	std::string path;

public:
	Turtle(int length);

	virtual void Update() override;
	virtual void Load() override;
	virtual void Render() override;
};

