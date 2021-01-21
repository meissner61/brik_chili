#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& position, Color color);
	void Draw(Graphics& gfx);
	void Update();
	void CheckCollision();

public:

	RectF screen{ 0.0f, float(Graphics::ScreenWidth), 0.0f, float(Graphics::ScreenHeight) };
	static constexpr int m_radius = 10;
	Vec2		 m_pos;
	Vec2	m_velocity{ 10.0f,-10.0f };
	Color	   m_color;

};