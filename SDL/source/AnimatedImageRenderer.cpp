#include "AnimatedImageRenderer.h"

void AnimatedImageRenderer::Load(std::string path)
{
	//Load the texture
	SDL_Surface* surface = IMG_Load(path.c_str());
	assert(surface);

	texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(texture);

	//Load frames
	frames = cols * rows;
	currentFrame = 0;
	targetRect = SDL_Rect{ 200, 0, 800, 500 };
	sourceRect = SDL_Rect{ 0, 0, surface->w / cols, surface->h / rows };

	//Free the surface
	SDL_FreeSurface(surface);
}

void AnimatedImageRenderer::Update(Vector2 position)
{
	currentFrameTime += TM->GetDt();
	int frameIncrement = (int)(currentFrameTime / maxFrameTime);

	currentFrameTime = ((currentFrameTime / maxFrameTime) - (float)frameIncrement) * maxFrameTime;

	currentFrame = (currentFrame + frameIncrement) % frames;
	int frameX = currentFrame % cols;
	int frameY = currentFrame / cols;

	sourceRect = { sourceRect.w * frameX, sourceRect.h * frameY, sourceRect.w, sourceRect.h };
}

void AnimatedImageRenderer::Render()
{
	SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);
}
