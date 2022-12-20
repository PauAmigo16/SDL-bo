#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "GameplayScene.h"

#define LL LevelLoader::GetInstance() 

class LevelLoader {
public:
	static LevelLoader* GetInstance();
	void LoadLevel(std::string path, GameplayScene* myGameplay);
private:
	static LevelLoader* instance;
	LevelLoader() = default;

};