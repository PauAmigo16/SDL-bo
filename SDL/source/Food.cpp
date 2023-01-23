#include "Food.h"
#include "Food.h"
#include "Food.h"

Food::Food(Log* log) : log(log)
{
    path = "../resources/Food.png";
    
    renderers.push_back(new ImageRenderer());
}

Food::~Food()
{
    delete renderers[0];
    delete texture;
}

void Food::Load() 
{
    renderers[0]->Load(path);
}

void Food::Update()
{
    bool canMove = log->IsInside(position.x+speed, size);
    if (canMove)
        position.x += speed;
    else
        speed *= (-1);

    renderers[0]->Update(position);
    bool inScreen = position.x < -size || position.x > 480;
    if (!inScreen)
        delete this;
}

void Food::Render()
{
    renderers[0]->Render();
}

bool Food::AttachedToPlayer()
{
    return attachedToPlayer;
}
