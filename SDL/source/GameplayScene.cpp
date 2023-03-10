#include "GameplayScene.h"

void GameplayScene::PrintMap(SDL_Renderer* renderer, int width, int height)
{
	SDL_Surface* surface = IMG_Load("resources/Assetsv2.png");
	AssetsTexture = SDL_CreateTextureFromSurface(renderer, surface);
	/*int tileX = 17;
	int tileY = 13;*/

	for (int i = 0; i < AssetsGridFilas + 2;  i++) {
		for (int j = 0; j < AssetsGridCols; j++) {
				AssetsSourceRect = SDL_Rect{ j * 16,i * 16,16,16};
				AssetsTargetRect = SDL_Rect{ j * width / (AssetsGridFilas + 2),i * height / AssetsGridCols,width / (AssetsGridFilas + 2),height / AssetsGridCols };
				SDL_RenderCopy(renderer, AssetsTexture, &AssetsSourceRect, &AssetsTargetRect);
		}
	}
	
}

void GameplayScene::OnEnter()
{
}

void GameplayScene::OnExit()
{
	
}

void GameplayScene::Update(float dt)
{
}

void GameplayScene::Render(SDL_Renderer* renderer, int width, int height)
{
	PrintMap(renderer, width, height);

}
