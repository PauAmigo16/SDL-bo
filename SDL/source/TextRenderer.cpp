#include "TextRenderer.h"

TextRenderer::~TextRenderer()
{
    delete texture;
}

void TextRenderer::Update(Vector2 position)
{
    targetRect.x = position.x;
    targetRect.y = position.y;
}

std::string TextRenderer::GetText()
{
    return text;
}

void TextRenderer::SetText(std::string text)
{
    this->text = text;
}
