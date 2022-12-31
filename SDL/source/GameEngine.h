#pragma once
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashScreenScene.h"
#include "MainMenuScene.h"
#include "LevelLoader.h"


class GameEngine
{
private: 
	//------ EXECUTION CONTROL
	bool isRunning;

	//------ SDL
	SDL_Window* window;
	SDL_Renderer* renderer;

	int windowWidth;
	int windowHeight;

	

	void InitSDL();
	void InitWindowAndRenderer();

	//----- RENDER
	int RandomNum();
	void Render();
	void FillScenes();


public:
	GameEngine(int x, int y);

	void Init();
	void Run();
	void Quit();

};

