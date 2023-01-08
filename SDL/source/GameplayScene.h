#pragma once
#include "Scene.h"
//#include "Frog.h"
#include "RenderManager.h"
#include "Spawner.h"
#include "GameObject.h"
#include <string>
#include <vector>

 const int AssetsGridFilas = 13;
 const int AssetsGridCols = 14;

class GameplayScene :
    public Scene
{
private:
    void SaveScore();
    void PrintMap(SDL_Renderer* renderer, int width, int height); 
    
    SDL_Texture* AssetsTexture;
    SDL_Rect AssetsTargetRect;
    SDL_Rect AssetsSourceRect;

    std::vector<GameObject*> gObjects;//Com no entenc els diferents vectors ja mho explicaras de moment amb un fem.

public:

    bool endPositions[5];
    static int level;
    int score;

    std::vector<Spawner*> spawners;

    std::vector<GameObject*> tiles;
    float maxTime;
    int endHazardChances;

    void AddGameObject(GameObject* gO);

    GameplayScene() = default;
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Render(SDL_Renderer* renderer, int width, int height) override;
};

