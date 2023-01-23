#pragma once
#include <SDL.h>

#define TM TimeManager::GetInstance()

class TimeManager
{
private:
	float dt;//ms
	float eTime;

	static TimeManager* instance;
	
	TimeManager();

public:
	static const float FPS;// = 60.0f;
	static const float TICK;// = 1.0f / 60.0f;

	static TimeManager* GetInstance();

	void Update();
	//TODO current time
	float GetCurrentTime();
	float GetDt();
};

