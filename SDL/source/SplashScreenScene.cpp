#include "SplashScreenScene.h"

void SplashScreenScene::Update()
{
	if (IM->CheckKeyState(SDLK_SPACE, PRESSED))
		SM->SetScene("Main Menu");
}

void SplashScreenScene::Render(SDL_Renderer* r, int width, int height)
{
}

void SplashScreenScene::OnEnter()
{
	std::cout << "Entering splash screen" << std::endl;
}

void SplashScreenScene::OnExit()
{
	std::cout << "Exiting splash screen" << std::endl;
}
