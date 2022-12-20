#include "RenderManager.h"

RenderManager* RenderManager::instance = nullptr;

RenderManager* RenderManager::GetInstance()
{
    if (instance == nullptr)
        instance = new RenderManager(224, 240, SDL_WINDOW_RESIZABLE);

    return instance;
}

SDL_Renderer* RenderManager::GetRenderer()
{
    return renderer;
}

void RenderManager::RenderScreen(int width, int height)
{
    //IM->GetResizeEvent(currentWinWidth, currentWinHeight);
    //Set the clear color for renderer
    SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);
    //Render the background
    SDL_RenderClear(renderer);
    SM->GetCurrentScene()->Render(renderer, width, height);
    SDL_RenderPresent(renderer);
}
