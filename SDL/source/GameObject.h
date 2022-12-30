#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "Renderer.h"

class GameObject
{
public:
	SDL_Texture* texture;
	SDL_Rect destinationRect;
	SDL_Rect sourceRect;	

	void LoadTexture(SDL_Renderer* renderer, std::string path);
	void SetPosition(int x, int y);
	GameObject() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
	Renderer* GetRenderer();

};
