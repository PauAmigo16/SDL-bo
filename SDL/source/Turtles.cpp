#include "Turtles.h"

Turtles::Turtles(int length) : length(length)
{
	path = "../resources/Turtle.png";
	for (int i = 0; i < length; i++)
		renderers.push_back(ImageRenderer());
}

void Turtles::Load() 
{
	for (auto renderer : renderers)
		renderer.Load(path);
}