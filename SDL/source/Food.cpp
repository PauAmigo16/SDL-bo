#include "Food.h"
#include "Food.h"
#include "Food.h"

Food::Food(Log* log) : log(log)
{
    path = "../resources/Food.png";
    
    renderers.push_back(new ImageRenderer());
}

void Food::Load() 
{
    renderers[0]->Load(path);
}

void Food::Update()
{
}

void Food::Render()
{
    renderers[0]->Render();
}

bool Food::AttachedToPlayer()
{
    return attachedToPlayer;
}
