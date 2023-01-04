#include "TimeManager.h"

const float TimeManager::FPS = 60.0f;
const float TimeManager::TICK = 1.0f / 60.0f;

TimeManager* TimeManager::instance = nullptr;

TimeManager::TimeManager()
{
    eTime = 0.0f;
    dt = 0.0f;
}

TimeManager* TimeManager::GetInstance()
{
   if (instance == nullptr)
        instance = new TimeManager();

    return instance;
}

void TimeManager::Update() 
{
    dt += SDL_GetTicks() - eTime;
    eTime = SDL_GetTicks();
}

float TimeManager::GetDt()
{
    return dt/1000.f;
}
