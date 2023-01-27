#include "InputManager.h"
#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager* InputManager::GetInstance()
{
    if (instance == nullptr)
        instance = new InputManager();

    return instance;
}

//Processes all the sdl input events and updates the keys map
void InputManager::Listen()
{
    for (auto i = keys.begin();
        i != keys.end(); i++) {

        if ((i->second & DOWN) > 0)
        {
            i->second = PRESSED;
        }
        else if ((i->second & UP) > 0)
        {
            i->second = RELEASED;
        }
    }

    SDL_GetMouseState(&mouseX, &mouseY);

    SDL_Event evt;

    while (SDL_PollEvent(&evt)) {

        if (evt.type == SDL_QUIT) {
            quitEvent = true;
        }
        else if (evt.type == SDL_KEYDOWN) {
            keys[evt.key.keysym.sym] = (KeyState)(DOWN | PRESSED);
        }
        else if (evt.type == SDL_KEYUP) {
            keys[evt.key.keysym.sym] = (KeyState)(UP | PRESSED);
        }
    }
}

//Returns true if the key is in the give state
bool InputManager::CheckKeyState(Sint32 key, KeyState state)
{
    if (keys.find(key) != keys.end())
    {
        return ((int)keys[key] & (int)state) > 0;
    }
    else
    {
        keys.emplace(key, UNDEFINED);

        return (state & UNDEFINED) > 0;
    }
}

int InputManager::GetMouseX()
{
    return mouseX;
}

int InputManager::GetMouseY()
{
    return mouseY;
}

bool InputManager::GetQuitEvent()
{
    return quitEvent;
}

Direction InputManager::GetDirection()
{
    if (CheckKeyState(SDLK_DOWN, DOWN))
        return Direction::DOWN;

    else if (CheckKeyState(SDLK_UP, DOWN))
        return Direction::UP;

    else if (CheckKeyState(SDLK_LEFT, DOWN))
        return Direction::LEFT;

    else if (CheckKeyState(SDLK_RIGHT, DOWN))
        return Direction::RIGHT;
}
