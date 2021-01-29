#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "FrameTimer.h"

//My attempt at making a ball
class Ball
{
public:
	Ball() = default;
	Ball(Vec2& position, Color color);
	Ball(Vec2& position);
	Ball(Vec2& position, Vec2& velocity);
	Ball(Vec2& position, Vec2& velocity, Color color);
	void Draw(Graphics& gfx);
	void DrawOutline(Graphics& gfx);
	void Update(float dt);
	void WallCollision(const RectF wall);
	RectF GetRect() const;
	void ShowRectF(Graphics& gfx) const;
	//void showRectF() const;

public:


	static constexpr int m_radius = 10;
	const RectF screen{ 0.0f, float(Graphics::ScreenWidth), 0.0f, float(Graphics::ScreenHeight) };
	Vec2		                     m_pos; //centered position
	Vec2	                    m_velocity;
	Color	         m_color = Colors::Red;
	Color	   m_rectColor = Colors::Green;
};