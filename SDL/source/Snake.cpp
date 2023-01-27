#include "Snake.h"

Snake::Snake(Log* log) :log(log)
{
	path = "../resources/SnakeAnimation.png";

	renderers.push_back(new AnimatedImageRenderer(size, 16, 30, 3, true, {255,255,255,255}, 255.f, 0.f, {0,0,32,16}, {0,0,32,16},3,1));
}

Snake::~Snake()
{
    delete renderers[0];
    delete texture;
}

void Snake::Load()
{
	renderers[0]->Load(path);
}

void Snake::Update()
{
    bool canMove = log->IsInside(position.x + speed, size);
    if (canMove)
        position.x += speed;
    else
        speed *= (-1);

    renderers[0]->Update(position);

    bool inScreen = position.x < -size || position.x > 480;
    if (!inScreen)
        delete this;
}

void Snake::Render()
{
    renderers[0]->Render();
}
