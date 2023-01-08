#include "ImageRenderer.h"

void ImageRenderer::Load(std::string path)
{
	//Load image
	SDL_Surface* surface = IMG_Load(path.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture);

	targetRect = SDL_Rect{ 0, 0, 255, 255 };//x,y,w,h

	SDL_FreeSurface(surface);
}

void ImageRenderer::Update(Vector2 position)
{
	targetRect.x = position.x;
	targetRect.y = position.y;
}

void ImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, NULL, &targetRect);
}
