#include "EndTileItem.h"

EndTileItem::EndTileItem(float duration, ItemType type)
    : duration(duration), type(type)
{
    switch (type)
    {
    case ItemType::FLY:
        path = "../resources/Fly.png";
        isLethal = false;
        renderers.push_back(new ImageRenderer());
        break;
    case ItemType::CROC:
        path = "../resources/EndTileCroc.png";
        isLethal = true;
        renderers.push_back(new AnimatedImageRenderer());
        break;
    case ItemType::FROG:
        path = "../resources/FullEndTile.png";
        isLethal = true;
        renderers.push_back(new ImageRenderer());
        break;
    }
}

void EndTileItem::Load()
{
    renderers[0]->Load(path);
}

void EndTileItem::Update()
{
}

void EndTileItem::Render()
{
}

bool EndTileItem::isFinished()
{
    return false;
}
