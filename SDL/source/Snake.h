#pragma once
#include "GameObject.h"
#include "Log.h"

class Snake :
    public GameObject
{
private:
    Log* log;

    std::string path;

public:
    Snake(Log* log);

    void Load() override;
    void Update() override;
    void Render() override;
};

