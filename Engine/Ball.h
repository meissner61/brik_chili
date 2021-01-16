#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2& position, Color color);
	void Draw(Graphics& gfx);
	void Update();
	void CheckCollision();

public:


	static constexpr int m_radius = 10;
	Vec2		 m_pos;
	Vec2	m_velocity{ 1,1 };
	Color	   m_color;

};