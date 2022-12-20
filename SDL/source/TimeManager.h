#pragma once

#define TM TimeManager::GetInstance() // va a hacer que cada vez que escribamos SM es como escribir la funcion

class TimeManager
{
private:
	float dt;

	static TimeManager* instance;
	
	TimeManager() = default;

public:
	static const float FPS;// = 60.0f;
	static const float TICK;// = 1.0f / 60.0f;

	TimeManager* GetInstance();

	void Update();

	float GetCurrentTime();
	float GetDeltaTime();
};

const float TimeManager::FPS = 60.0f;
const float TimeManager::TICK = 1.0f / 60.0f;