#include "Snake.h"

Snake::Snake(Log* log) :log(log)
{
	path = "../resources/SnakeAnimation.png";

	renderers.push_back(AnimatedImageRenderer());
}

void Snake::Load()
{
	renderers[0].Load(path);
}
