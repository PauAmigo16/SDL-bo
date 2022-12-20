#pragma once
#include "Renderer.h"
class ImageRenderer :
    public Renderer
{
public:
    ImageRenderer(SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect) : Renderer(color, alpha, rotation, targetRect, sourceRect) {}

    virtual void Load(std::string path) override;
    virtual void Update() override;
    virtual void Render() override;
};

