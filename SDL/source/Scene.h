#pragma once
#include <SDL.h>

class Scene {
public:
	virtual void Update(float dt) = 0;
	virtual void Render(SDL_Renderer* renderer, int width, int height) = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
};