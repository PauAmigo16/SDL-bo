#pragma once
#include "GameObject.h"

class Log :
	public GameObject
{
private:
	std::string startLogPath;
	std::string midLogPath;
	std::string endLogPath;

protected:
	int length;
	int size = length * 16;

public:
	Log(int length, int yPosition);
	~Log();

	virtual void Load() override;
	virtual void Update() override;
	virtual void Render() override;

	bool IsInside(int x, int objSize);
};
