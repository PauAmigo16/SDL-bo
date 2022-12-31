#pragma once
#include "ImageRenderer.h"
#include "TimeManager.h"
#include "RenderManager.h"
#include <assert.h>
#include <SDL.h>

class AnimatedImageRenderer :
    public ImageRenderer
{
private:
    int cols;
    int rows;

    int frameWidth;
    int frameHeight;

    int frames;
    int currentFrame=0;
    int fps;

    float currentFrameTime=0.0f;
    float maxFrameTime = 1.f / 28.f;

    bool looping;

public:
    AnimatedImageRenderer(int frameWidth=16, int frameHeight=16, int fps=30, bool looping=true, SDL_Color color={255,255,255,255}, float alpha=255, float rotation=0, SDL_Rect targetRect={0,0,16,16}, SDL_Rect sourceRect={0,0,16,16}, int cols=1, int rows=3)
        : frameWidth(frameWidth), frameHeight(frameHeight), fps(fps), looping(looping), ImageRenderer(color, alpha, rotation, targetRect, sourceRect), cols(cols), rows(rows){}

    void Load(std::string path) override;
    void Update() override;
    void Render() override;
};

