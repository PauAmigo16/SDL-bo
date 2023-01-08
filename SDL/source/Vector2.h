#pragma once
#include <math.h>

class Vector2
{
public:
	float x;
	float y;

	Vector2() = default;
	Vector2(float x, float y) : x(x), y(y) {}

	void NormalizeVector();

	Vector2 operator + (Vector2 a)
	{
		return Vector2(a.x + x, a.y + y);
	}
	Vector2 operator - (Vector2 a)
	{
		return Vector2(a.x - x, a.y - y);
	}
	Vector2 operator * (float scale)
	{
		return Vector2(x * scale, y * scale);
	}
	Vector2 operator / (float scale)
	{
		return Vector2(x / scale, y / scale);
	}
	bool operator== (Vector2 a)
	{
		return (a.x == x && a.y == y);
	}
	bool operator != (Vector2 a)
	{
		return !(a.x == x && a.y == y);
	}
};

