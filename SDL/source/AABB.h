#pragma once
#include "Vector2.h"
#include "RenderManager.h"

class AABB
{
private:
	Vector2 topLeft;
	Vector2 size;

public:
	AABB() = default;
	AABB(Vector2 topLeft, Vector2 size);

	Vector2 GetTopLeft();
	Vector2 GetSize();

	void SetTopLeft(Vector2 point);
	void SetSize(Vector2 size);

	bool CheckOverlappingPoint(Vector2 point);
	bool CheckOverlapingBox(const AABB* box);
};

