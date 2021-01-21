#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& position, Color color);
	Ball(Vec2& position);
	void Draw(Graphics& gfx);
	void Update();
	void CheckCollision();

public:
	static constexpr int m_radius = 10;
	const RectF screen{ 0.0f, float(Graphics::ScreenWidth), 0.0f, float(Graphics::ScreenHeight) };
	Vec2		 m_pos;
	Vec2	m_velocity{ 5.0f,-5.0f };
	Color	   m_color = Colors::Red;
	RectF ballRec{ m_pos.x - float(m_radius), m_pos.x + float(m_radius),
		m_pos.y - float(m_radius), m_pos.y + float(m_radius) };
};