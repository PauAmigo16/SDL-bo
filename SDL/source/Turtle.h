#pragma once
#include "GameObject.h"

class Turtle: public GameObject
{
private:
	bool diving;
	bool underwater;
	int length;
	std::string path;

public:
	Turtle(int length, int _secondChance, bool diving)
		: length(length), diving(diving){}
	virtual void Update() override;
	virtual void Load() override;
	virtual void Render() override;
};

