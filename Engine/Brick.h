#pragma once
#include "RectF.h"
#include "Graphics.h"

class Brick
{

public:
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx)const;
	void CheckCollision();
public:

	RectF rect;
	Color color;
	bool destroyed = false;
};