#pragma once
#include "Renderer.h"
#include <SDL_ttf.h>

class TextRenderer :
    public Renderer
{
private:
    std::string text;

public:
    TextRenderer(std::string text, SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect) : Renderer(color, alpha, rotation, targetRect, sourceRect) {}

    void Load(std::string path) override;
    void Update() override;
    void Render() override;

    std::string GetText();

    void SetText(std::string text);
};

