#include "Crocodile.h"

Crocodile::Crocodile(float openMouthDuration, float closedMouthDuration, int length, int yPosition)
   : Log(length,yPosition), openMouthDuration(openMouthDuration), closedMouthDuration(closedMouthDuration)
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
	//laod all paths
	renderers[0]->Load(bodyPath);
	renderers[1]->Load(openMouthPath);
	renderers[2]->Load(closedMouthPath);

	//load positions
	renderers[0]->SetPosition()
}

void Crocodile::Update()
{
	position.x += speed;
}

void Crocodile::Render()
{
	renderers[1]->Render();
	if (mouthOpen)
		renderers[1]->Render();
	else
		renderers[2]->Render();
}
