#pragma once
#include "../dependencies/inc/XML/rapidxml.hpp"
#include "../dependencies/inc/XML/rapidxml_iterators.hpp"
#include "../dependencies/inc/XML/rapidxml_print.hpp"
#include "../dependencies/inc/XML/rapidxml_utils.hpp"
#include "LogSpawner.h"
#include "RoadSpawner.h"
#include "TurtleSpawner.h"
#include "GameplayScene.h"
#include "EndTileItem.h"
#include <iostream>
#include <fstream>
#include <sstream>

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