#include "DivingTurtles.h"

DivingTurtles::~DivingTurtles()
{
	for (auto renderer : renderers)
		delete renderer;
}

void DivingTurtles::Load()
{
    renderers[1]->Load(path);
}

void DivingTurtles::Update()
{
	position.x += speed;

	for (auto renderer : renderers)
		renderer->Update(position);

	bool inScreen = position.x < -size || position.x > 480;
	if (!inScreen)
		delete this;
}

void DivingTurtles::Render()
{
    renderers[1]->Render();
}

bool DivingTurtles::IsDiving()
{
    return isDiving;
}
