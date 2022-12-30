#pragma once
#include "source/GameObject.h"
#include "source/Log.h"
class Food : public GameObject
{
private:
	Log* log;
	bool attachedToPlayer;

public:
	Food(Log* log);
	void override Update();
};

