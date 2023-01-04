#include "SplashScreenScene.h"

void SplashScreenScene::Update()
{
	if (IM->CheckKeyState(SDLK_SPACE, PRESSED))
		SM->SetScene("Main Menu");
}

void SplashScreenScene::Render(SDL_Renderer* r, int width, int height)
{
	//SDL_Surface* surface = IMG_Load("./resources/Assetsv2.png");

	//SDL_Texture* AssetsTexture = SDL_CreateTextureFromSurface(r, surface);
	///*int tileX = 17;
	//int tileY = 13;*/
	//auto SourceRect = SDL_Rect{ 16, 16,16,16 };
	//auto TargetRect = SDL_Rect{ width, height,width,height };
	//		SDL_RenderCopy(r, AssetsTexture, &SourceRect, &TargetRect);
	//SDL_FreeSurface(surface);
}

void SplashScreenScene::OnEnter()
{
	std::cout << "Entering splash screen" << std::endl;
}

void SplashScreenScene::OnExit()
{
	std::cout << "Exiting splash screen" << std::endl;
}
