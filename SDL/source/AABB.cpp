#include "AABB.h"

AABB::AABB(Vector2 topLeft, Vector2 size) : topLeft(topLeft), size(size)
{
}

Vector2 AABB::GetTopLeft()
{
	return topLeft;
}

Vector2 AABB::GetSize()
{
	return size;
}

void AABB::SetTopLeft(Vector2 point)
{
	topLeft = point;
}

void AABB::SetSize(Vector2 size)
{
	this->size = size;
}

bool AABB::CheckOverlappingPoint(Vector2 point)
{
	return (((topLeft.x < point.x) && point.x < (topLeft.x + size.x)) && ((topLeft.y < point.y) && point.y < (topLeft.y + size.y)));
}

bool AABB::CheckOverlapingBox(const AABB* box)
{
	//Top left corner
	bool checkCollision = ((topLeft.x < box->topLeft.x&& box->topLeft.x < (topLeft.x + size.x))) && ((topLeft.y < box->topLeft.y&& box->topLeft.y < (topLeft.y + size.y)));
	if (checkCollision)
		return true;

	//Top right corner
	checkCollision = (topLeft.x < (box->topLeft.x + box->size.x) && (box->topLeft.x + box->size.x) < (topLeft.x + size.x)) && (topLeft.y < box->topLeft.y&& box->topLeft.y < (topLeft.y + size.y));
	if (checkCollision)
		return true;

	//Bottom left corner
	checkCollision = (topLeft.x < box->topLeft.x&& box->topLeft.x < (topLeft.x + size.x)) && (topLeft.y < (box->topLeft.y + box->size.y) && (box->topLeft.y + box->size.y) < (topLeft.y + size.y));
	if (checkCollision)
		return true;

	//Esquina inferior derecha
	checkCollision = (topLeft.x < (box->topLeft.x + box->size.x) && (box->topLeft.x + box->size.x) < (topLeft.x + size.x)) && (topLeft.y < (box->topLeft.y + box->size.y) && (box->topLeft.y + box->size.y) < (topLeft.y + size.y));
	if (checkCollision)
		return true;

	return false;
}


