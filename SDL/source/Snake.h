#pragma once
#include "GameObject.h"
#include "Log.h"

class Snake :
    public GameObject
{
private:
    Log* log;
public:
    Snake(Log* log):GameObject(){}

    void Update() override;
    void Render() override;
};

