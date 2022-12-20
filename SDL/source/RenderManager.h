#pragma once
#include <SDL.h>
#include <vector>
#include "SceneManager.h"
#include "InputManager.h"

#define RM RenderManager::GetInstance()

class RenderManager
{
private:
	static RenderManager* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;

	RenderManager(int width, int height, int flags)
	{
		SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);
	}

public:
	static const float windowWidth;
	static const float windowHeight;

	static RenderManager* GetInstance();
	SDL_Renderer* GetRenderer();
	void RenderScreen(int width, int height);
};

