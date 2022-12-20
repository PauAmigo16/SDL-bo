#pragma once
#include "Scene.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <iostream>

class SplashScreenScene :
    public Scene
{
    // Inherited via Scene
    virtual void Update(float dt) override;
    virtual void Render(SDL_Renderer* renderer, int width, int height) override;
    virtual void OnEnter() override;
    virtual void OnExit() override;
};

