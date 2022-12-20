#include "Renderer.h"

void Renderer::SetColor(SDL_Color color)
{
	this->color = color;
}

void Renderer::SetAlpha(float alpha)
{
	this->alpha = alpha;
}

void Renderer::SetPosition(Vector2 position)
{
	targetRect.x = position.x;
	targetRect.y = position.y;
}

void Renderer::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void Renderer::SetScale(Vector2 scale)
{
	this->scale = scale;
}

SDL_Color Renderer::GetColor()
{
	return color;
}

float Renderer::GetAlpha()
{
	return alpha;
}
