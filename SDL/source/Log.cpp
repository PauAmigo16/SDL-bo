#include "Log.h"

Log::Log(int length, int yPosition)
	:length(length)
{
	startLogPath = "../resources/LogStart.png";
	midLogPath = "../resources/LogMiddle.png";
	endLogPath = "../resources/LogEnd.png";

	for (int i = 0; i < length; i++)
	{
		renderers.push_back(new ImageRenderer());
	}

	position.y = yPosition;

	if (yPosition % 2 == 0)
		speed = 1;
	else
		speed = -1;

	if (speed < 0)
		position.x = 208;
	else
		position.x = 0;
}

Log::~Log() 
{
	for (auto renderer : renderers)
		delete renderer;

	delete texture;
}

void Log::Load()
{
	//load all sprites
	renderers[0]->Load(startLogPath);
	renderers[length - 1]->Load(endLogPath);
	for (int i = 1; i < length - 1; i++)
		renderers[i]->Load(midLogPath);

	//load positions
	Vector2 i = position;
	for (auto renderer : renderers)
	{
		renderer->SetPosition(position);
		position.x -= (16 * speed);
	}
	position = i;
}

void Log::Update()
{
	position.x += speed;

	for (auto renderer : renderers)
		renderer->Update(position);

	bool inScreen = position.x < -size || position.x > 480;
	if (!inScreen)
		delete this;
}

void Log::Render()
{
	for (auto renderer : renderers)
		renderer->Render();
}

bool Log::IsInside(int x, int objSize)
{
	return x <= position.x && (x + objSize) >= (position.x - size);
}
