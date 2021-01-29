#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"
#include "Keyboard.h"
#include "FrameTimer.h"

class Paddle
{
public:

	Paddle() = default;

	void Draw(Graphics& gfx) const;
	void Move(Keyboard& kbd, float dt);
	void CheckWallCollision(RectF wall);
	void TopCollision(Ball& ball);
	RectF GetRect() const;

public:

	static constexpr int m_width = 100;
	static constexpr int m_height = 20;
	Vec2 m_pos{ 500.0f, 400.0f};
	Vec2 m_vel{ 500.0f,0.0f };


	Color m_color = Colors::LightGray;
};