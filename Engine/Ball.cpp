#include "Ball.h"

Ball::Ball(Vec2& position, Color color)
	:
	m_pos(position),
	m_color(color)
{
}

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawCircle(m_pos.x, m_pos.y, m_radius, m_color);
}

void Ball::Update()
{
	m_pos += m_velocity;
}

void Ball::CheckCollision()
{
	
}
