#pragma once
#include "Renderer.h"
#include <SDL_ttf.h>

class TextRenderer :
    public Renderer
{
private:
    std::string text;

    TTF_Font* font;

    int charSize;
    int width;
    int height;

public:
    TextRenderer(std::string text, int size, SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect) : Renderer(color, alpha, rotation, targetRect, sourceRect), text(text), charSize(size) {}
    ~TextRenderer();

    void Load(std::string path) override;
    void Update(Vector2 position) override;
    void Render() override;

    std::string GetText();
    void SetText(std::string text);
};

