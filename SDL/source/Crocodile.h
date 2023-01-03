#pragma once
#include "Log.h"

class Crocodile :
    public Log
{
private:

public:
    Crocodile (int length, int _secondChance) : Log(length, _secondChance){}
};

