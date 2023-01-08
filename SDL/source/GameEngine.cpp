#include "GameEngine.h"

GameEngine::GameEngine(int x, int y)
	: windowHeight(y), windowWidth(x), isRunning(true)
{
	
}

#pragma region INITIALIZATION

//Initializes SDL, windows and renderers
void GameEngine::Init()
{
	InitSDL();
	InitWindowAndRenderer();
	FillScenes();
	LL->LoadLevel("resources/sample_level.xml", dynamic_cast<GameplayScene*>(SM->GetScene("Gameplay Scene")));
	
	//logo.LoadTexture(renderer, "resources/Assetsv2.png");


}

//Ensures that SDL is working and can run
void GameEngine::InitSDL()
{
	//Load SDL and check if it is correct
	int result = SDL_Init(SDL_INIT_VIDEO);

	srand(time(NULL));

	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

//Create a window and a renderer
void GameEngine::InitWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer);
	
	bool success = result >= 0;
	if (!success)
		throw SDL_GetError();
}

#pragma endregion INITIALIZATION


#pragma region RENDER

//Game loop
void GameEngine::Run()
{
	//BEFORE THE GAME LOOP
	
	//GAME LOOP
	while (isRunning)
	{
		IM->Listen();
		isRunning = !IM->GetQuitEvent();
		SM->GetCurrentScene()->Update();

		//RENDER
		//Set the clear color for renderer
		SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);
		//Render the background
		SDL_RenderClear(renderer);
		SM->GetCurrentScene()->Render(renderer, windowHeight, windowWidth);
		SDL_RenderPresent(renderer);
	}
}

int GameEngine::RandomNum()
{
	int num = rand() % 255;
	return num;
}

#pragma endregion RENDER

//Destroys all windows and renderers
void GameEngine::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	//Destroys all renderers
	//Destroys all windows
	//Quits SDL
}

void GameEngine::FillScenes() {
	auto gameplay = new GameplayScene();
	SM->ClearScenes();
	SM->AddScene("Splash Screen", new SplashScreenScene());
	SM->AddScene("Main Menu", new MainMenuScene());
	//SM->AddScene("Main Menu", new MainMenuScene());
	SM->AddScene("Gameplay Scene", gameplay);

	LL->LoadLevel(". / resources/sample_level.xml", gameplay);

	SM->SetScene("Gameplay Scene");
}
