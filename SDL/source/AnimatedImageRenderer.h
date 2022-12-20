#pragma once
#include "ImageRenderer.h"
class AnimatedImageRenderer :
    public ImageRenderer
{
private:
    int frameWidth;
    int frameHeight;
    int fps;
    bool looping;

public:
    AnimatedImageRenderer(int frameWidth, int frameHeight, int fps, bool looping, SDL_Color color, float alpha, float rotation, SDL_Rect targetRect, SDL_Rect sourceRect)
        : frameWidth(frameWidth), frameHeight(frameHeight), fps(fps), looping(looping), ImageRenderer(color, alpha, rotation, targetRect, sourceRect){}

    void Load(std::string path) override;
    void Update() override;
    void Render() override;
};

