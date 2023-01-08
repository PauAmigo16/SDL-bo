#pragma once
#include <assert.h>
#include "Renderer.h"

class ImageRenderer :
    public Renderer
{

public:
    ImageRenderer(SDL_Color color = { 255,255,255, 255 }, float alpha = 0, float rotation = 0, SDL_Rect targetRect = { 0,0,16,16 }, SDL_Rect sourceRect = { 16,16 })
        : Renderer(color, alpha, rotation, targetRect, sourceRect) {}

    virtual void Load(std::string path) override;
    virtual void Update(Vector2 position) override;
    virtual void Render() override;
};
