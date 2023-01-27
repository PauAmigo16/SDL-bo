#pragma once

#include <map>
#include <unordered_map>
#include <iostream>
#include "SDL.h"
#include "Direction.h"

#define IM InputManager::GetInstance()

enum KeyState {
    UNDEFINED = 1,  //code trues to access key but it hasn't been registered yet
    DOWN = 2,        //frame that the the key is pressed
    PRESSED = 4,    //the key is pressed
    UP = 8,            //frame that the key is released
    RELEASED = 16    //the key is released
};

class InputManager
{
private:
    InputManager() : quitEvent(false), mouseX(0), mouseY(0) {}

    static InputManager* instance;

    std::unordered_map<Sint32, KeyState> keys;

    int mouseX, mouseY;

    bool quitEvent;

public:
    static InputManager* GetInstance();

    void Listen();

    int GetMouseX();
    int GetMouseY();

    bool CheckKeyState(Sint32 key, KeyState state);
    bool GetQuitEvent();

    Direction GetDirection();
};