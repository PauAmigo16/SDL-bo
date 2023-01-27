#pragma once
#include "GameObject.h"
#include "Log.h"

class Food :
    public GameObject
{
private:
    Log* log;

    bool attachedToPlayer;

    std::string path;
    
    int size = 16;

public:

    Food(Log* log);
    ~Food();

    void Load() override;
    void Update() override;
    void Render() override;

    bool AttachedToPlayer();
};

