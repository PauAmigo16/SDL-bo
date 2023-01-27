#pragma once
#include "GameObject.h"
#include "Log.h"

class Snake :
    public GameObject
{
private:
    Log* log;

    std::string path;

    int size = 32;

public:
    Snake(Log* log);
    ~Snake();

    void Load() override;
    void Update() override;
    void Render() override;
};

