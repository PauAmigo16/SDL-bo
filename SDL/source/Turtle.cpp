#include "Turtle.h"

Turtle::Turtle(int length) : length(length)
{
	path = "../resources/Turtle.png";
	for (int i = 0; i < length; i++)
		renderers.push_back(new ImageRenderer());
}

Turtle::~Turtle() 
{
	for (auto renderer : renderers)
		delete renderer;

	delete texture;
}

void Turtle::Update()
{
	position.x += speed;

	for (auto renderer : renderers)
		renderer->Update(position);

	bool inScreen = position.x < -size || position.x > 480;
	if (!inScreen)
		delete this;
}

void Turtle::Load()
{
	for (auto renderer : renderers)
		renderer->Load(path);
}

void Turtle::Render()
{
}
