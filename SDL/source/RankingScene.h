#pragma once
#include "Scene.h"
class RankingScene :
    public Scene
{
private:
    void LoadScene();

public:
    RankingScene() = default;

    void OnEnter() override;
    void OnExit() override;
    void Update(float dt) override;
    void Render(SDL_Renderer*, int width, int height) override;
};

