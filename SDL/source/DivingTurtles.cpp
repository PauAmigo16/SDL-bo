#include "DivingTurtles.h"

void DivingTurtles::Load()
{
    renderers[1]->Load(path);
}

void DivingTurtles::Update()
{

}

void DivingTurtles::Render()
{
    renderers[1]->Render();
}

bool DivingTurtles::IsDiving()
{
    return isDiving;
}
