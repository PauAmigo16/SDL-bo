#include "Turtle.h"

Turtle::Turtle(int length) : length(length)
{
	path = "../resources/Turtle.png";
	for (int i = 0; i < length; i++)
		renderers.push_back(new ImageRenderer());
}

void Turtle::Update()
{
}

void Turtle::Load()
{
	for (auto renderer : renderers)
		renderer->Load(path);
}

void Turtle::Render()
{
}
