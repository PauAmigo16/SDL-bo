#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "RenderManager.h"
#include <iostream>

class SplashScreenScene :
    public Scene
{
private:
    std::string path;

public:
    // Inherited via Scene
    virtual void Update() override;
    virtual void Render(SDL_Renderer* renderer, int width, int height) override;
    virtual void OnEnter() override;
    virtual void OnExit() override;
};

