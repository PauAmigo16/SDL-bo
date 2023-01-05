#include "Food.h"

Food::Food(Log* log) : log(log)
{
    path = "../resources/Food.png";
    
    renderers.push_back(ImageRenderer());
}

void Food::Load() 
{
    renderers[0].Load(path);
}

bool Food::AttachedToPlayer()
{
    return attachedToPlayer;
}
