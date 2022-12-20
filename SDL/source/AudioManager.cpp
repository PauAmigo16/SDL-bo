#include "AudioManager.h"

AudioManager* AudioManager::GetInstance()
{
    if (instance == nullptr)
        instance = new AudioManager();

    return instance;
}

void AudioManager::Mute()
{
    muted = true;
}

void AudioManager::Unmute()
{
    muted = false;
}

bool AudioManager::GetMuted()
{
    return muted;
}
