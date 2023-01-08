#include "Crocodile.h"

Crocodile::Crocodile(float openMouthDuration, float closedMouthDuration, int length)
   : Log(length), openMouthDuration(openMouthDuration), closedMouthDuration(closedMouthDuration)
{
	bodyPath = "../resources/CrocBody.png";
	openMouthPath = "../resources/CrocOpenMouth.png";
	closedMouthPath = "../resources/CrocClosedMouth.png";
	for (int i = 0; i < 3; i++) {
		auto renderer = new  ImageRenderer();
		renderers.push_back(renderer);
	}
}

bool Crocodile::isMouthOpen()
{
	return mouthOpen;
}

void Crocodile::Load()
{
	renderers[0]->Load(bodyPath);
	renderers[1]->Load(openMouthPath);
	renderers[2]->Load(closedMouthPath);
}

void Crocodile::Update()
{
}

void Crocodile::Render()
{
}
