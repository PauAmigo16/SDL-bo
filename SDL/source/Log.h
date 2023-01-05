#pragma once
#include "GameObject.h"

class Log :
	public GameObject
{
private:
	int length;

	std::string startLogPath;
	std::string midLogPath;
	std::string endLogPath;

public:
	Log(int length);

	virtual void Load() override;
	virtual void Update() override;
	virtual void Render() override;
};
