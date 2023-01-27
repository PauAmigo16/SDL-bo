#pragma once
#include <SDL_mixer.h>
#include <unordered_map>
#include <queue>
#include <string>

#define AM AudioManager::GetInstance()

class AudioManager
{
private:
	std::unordered_map<int, Mix_Chunk*> clips;
	std::unordered_map<int, Mix_Music*> songs;

	bool muted;

	std::queue<int> avaliableIDs;

	static AudioManager* instance;

	AudioManager() = default;

public:
	static AudioManager* GetInstance();

	int LoadClip(std::string path);
	void PlayClip(int ID);
	void StopClip(int ID);

	int LoadMusic(std::string path);
	void PlaySong(int ID);
	void StopSong(int ID);

	void Mute();
	void Unmute();
	bool GetMuted();
};

