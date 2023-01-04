#pragma once

#define TM TimeManager::GetInstance()

const float TimeManager::FPS = 60.0f;
const float TimeManager::TICK = 1.0f / 60.0f;

class TimeManager
{
private:
	float dt;

	static TimeManager* instance;
	
	TimeManager() = default;

public:
	static const float FPS;// = 60.0f;
	static const float TICK;// = 1.0f / 60.0f;

	static TimeManager* GetInstance();

	void Update();

	float GetCurrentTime();
	float GetDt();
};

