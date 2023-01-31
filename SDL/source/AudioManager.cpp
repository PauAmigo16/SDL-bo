#include "AudioManager.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager* AudioManager::GetInstance()
{
    if (instance == nullptr)
        instance = new AudioManager();

    return instance;
}

int AudioManager::LoadClip(std::string path)
{
    return 0;
}

void AudioManager::PlayClip(int ID)
{
}

void AudioManager::StopClip(int ID)
{
}

int AudioManager::LoadMusic(std::string path)
{
    return 0;
}

void AudioManager::PlaySong(int ID)
{
}

void AudioManager::StopSong(int ID)
{
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
