#pragma once
#include "GameObject.h"

class Turtle : public GameObject
{
private:
	std::string path;

protected:
	int length;
	int size = length * 16;

public:
	Turtle(int length);
	~Turtle();

	virtual void Update() override;
	virtual void Load() override;
	virtual void Render() override;
};

