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
		position.x -= 16;
	}
	position = i;
}

void Log::Update()
{
	position.x += speed;
	for (auto renderer : renderers)
		renderer->AddPosition(speed);
}

void Log::Render()
{
	for (auto renderer : renderers)
		renderer->Render();
}