#include "TextRenderer.h"

std::string TextRenderer::GetText()
{
    return text;
}

void TextRenderer::SetText(std::string text)
{
    this->text = text;
}

void TextRenderer::Load(std::string path)
{
    //load font
    font = TTF_OpenFont(path.c_str(), charSize);
    assert(font);

    //Load text surface
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    assert(surface);

    texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
    assert(texture);

    height = surface->h;
    width = surface->w;

    SDL_FreeSurface(surface);
}

void TextRenderer::Render()
{
    SDL_RenderCopy(RM->GetRenderer(), texture, &sourceRect, &targetRect);
}
