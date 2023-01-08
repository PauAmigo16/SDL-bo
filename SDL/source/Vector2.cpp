#include "Vector2.h"

void Vector2::NormalizeVector()
{
	float sR = sqrt(this->x * this->x + this->y * this->y);
	this->x /= sR;
	this->y /= sR;
}
