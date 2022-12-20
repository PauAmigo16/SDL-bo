#pragma once
#include "Scene.h"
#include <iostream>
#include "UIText.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SDL_ttf.h"
#include <cassert>


class MainMenuScene :
    public Scene
{
private:
    UIText sampleText;
    TTF_Font* font;
    float buttonAngle;

public:
    //Inherit via Scene
    virtual void Update(float dt) override;
    virtual void Render(SDL_Renderer* renderer, int width, int height) override;
    virtual void OnEnter() override;
    virtual void OnExit() override;
    float ButtonAnimation(float buttonAngle);
    
};

