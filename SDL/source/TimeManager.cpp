#include "TimeManager.h"

TimeManager* TimeManager::instance = nullptr;


TimeManager* TimeManager::GetInstance()
{
   if (instance == nullptr)
        instance = new TimeManager();

    return instance;
}

float TimeManager::GetDt()
{
    return dt;
}
