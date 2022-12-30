#pragma once
#include "Scene.h"
//#include "Spawner.h"
//#include "Frog.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include "RenderManager.h"

 const int AssetsGridFilas = 13;
 const int AssetsGridCols = 14;

class GameplayScene :
    public Scene
{
private:
    void SaveScore();
    void PrintMap(SDL_Renderer* renderer, int width, int height);
    void LoadLevelFromFile(std::string path);    
    
    SDL_Texture* AssetsTexture;
    SDL_Rect AssetsTargetRect;
    SDL_Rect AssetsSourceRect;

    std::vector<GameObject*> tilesLine1;
    std::vector<GameObject*> tilesLine2;
    std::vector<GameObject*> tilesLine3;
    std::vector<GameObject*> tilesLine4;



public:
    bool endPositions[5];
    static int level;
    int score;

    /*Spawner spawner;
    Frog player;*/
    std::vector<GameObject*> tiles;
    float maxTime;
    int endHazardChances;

    GameplayScene() = default;
    void OnEnter() override;
    void OnExit() override;
    void Update(float dt) override;
    void Render(SDL_Renderer* renderer, int width, int height) override;
};

