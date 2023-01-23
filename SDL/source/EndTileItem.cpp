#include "EndTileItem.h"

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
