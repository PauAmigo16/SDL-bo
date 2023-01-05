#pragma once
#include <SDL_image.h>
#include <string>
#include "Vector2.h"

class Renderer
{
protected:
	SDL_Texture* texture;
	SDL_Color color;
	SDL_Rect sourceRect;
	SDL_Rect targetRect;

	Vector2 scale;

	float alpha;
	float rotation;

public:
	Renderer(SDL_Color color, float alpha, float rotation, SDL_Rect sourceRect, SDL_Rect targetRect) : 
		color(color), alpha(alpha), rotation(rotation), sourceRect(sourceRect), targetRect(targetRect) 
	{

	}

	virtual void Load(std::string path) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	void SetColor(SDL_Color color);
	void SetAlpha(float alpha);
	void SetPosition(Vector2 position);
	void SetRotation(float rotation);
	void SetScale(Vector2 scale);

	SDL_Color GetColor();
	float GetAlpha();

};

