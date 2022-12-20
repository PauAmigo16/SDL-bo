#pragma once
class Vector2
{
public:
	float x;
	float y;

	Vector2() = default;
	Vector2(float x, float y) : x(x), y(y) {}

	void Normalize();
};

