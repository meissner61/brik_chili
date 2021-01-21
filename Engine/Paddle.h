#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Paddle
{
public:

	Paddle() = default;
	Paddle(Vec2& position, Ball& ball);
	void Draw(Graphics& gfx);
	void Move(int direction);
	void CheckCollision(Ball& ball);

public:

	static constexpr int m_width = 100;
	static constexpr int m_height = 20;
	Vec2 m_pos{};
	Vec2 m_vel{ 10.0f,0.0f };


	Color m_color = Colors::LightGray;
	RectF m_rect{ m_pos,m_pos.x + m_width,m_pos.y + m_height };
};