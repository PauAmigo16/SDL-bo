#include "Log.h"

Log::Log(int length) :length(length)
{
	startLogPath = "../resources/LogStart.png";
	midLogPath = "../resources/LogMiddle.png";
	endLogPath = "../resources/LogEnd.png";

	for (int i = 0; i < length; i++)
	{
		renderers.push_back(new ImageRenderer());
	}
}

void Log::Load()
{
	renderers[0]->Load(startLogPath);
	renderers[length - 1]->Load(endLogPath);
	for (int i = 1; i < length - 1; i++)
		renderers[i]->Load(midLogPath);
}

void Log::Update()
{
}

void Log::Render()
{
}