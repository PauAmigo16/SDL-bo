#pragma once
#include "GameObject.h"

enum class ItemType{FLY, CROC, FROG};

class EndTileItem :
    public GameObject
{
private:
    float duration;
    float currentDuration;

    bool isLethal;

    std::string path; 

    ItemType type;

public:
    EndTileItem(float dangerChance, float flyChance) {};

    void Load() override;
    void Update() override;
    void Render() override;

    bool isFinished();
};

