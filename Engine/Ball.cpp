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
	if (m_pos.x - m_radius - 1 <= screen.left)
	{
		m_velocity.x *= (-1);
	}

	if (m_pos.x + m_radius + 1 >= screen.right)
	{
		m_velocity.x *= (-1);
	}

	if (m_pos.y - m_radius - 1 <= screen.top)
	{
		m_velocity.y *= (-1);
	}
	
	if (m_pos.y + m_radius+1 >= screen.bottom-20.0f)
	{
		m_velocity.y *= (-1);
	}
}
