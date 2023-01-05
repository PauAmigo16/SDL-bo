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
    
public:

    Food(Log* log);

    void Load() override;
    void Update() override;
    void Render() override;

    bool AttachedToPlayer();
};

