#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "GameplayScene.h"

#define LL LevelLoader::GetInstance() 

class LevelLoader {
private:
	static LevelLoader* instance;
	LevelLoader() = default;

public:
	static LevelLoader* GetInstance();
	void LoadLevel(std::string path, GameplayScene* myGameplay);
	void SaveLevel(std::string path, GameplayScene* myGameplay);
};