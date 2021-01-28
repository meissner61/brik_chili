#include "Ball.h"


Ball::Ball(Vec2& position, Color color)
	:
	m_pos(position),
	m_color(color)
{
}

Ball::Ball(Vec2& position)
	:
	m_pos(position)
{
}

Ball::Ball(Vec2 & position, Vec2 & velocity)
	:
	m_pos(position),
	m_velocity(velocity)
{

}

Ball::Ball(Vec2 & position, Vec2 & velocity, Color color)
	:
	m_pos(position),
	m_velocity(velocity),
	m_color(color)
{
}

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawCircle(int(m_pos.x), int(m_pos.y), m_radius, m_color);
}

void Ball::Update(float dt)
{
	m_pos += m_velocity * dt;
}

void Ball::WallCollision(const RectF wall)
{
	const RectF ballRect = GetRect();

	if (ballRect.left < wall.left)//left wall
	{
		m_pos.x += wall.left - ballRect.left;
		m_velocity.x = -m_velocity.x;
		//m_pos.x = 11.0f;
		//m_velocity.x *= (-1);
	}

	if (ballRect.right > wall.right)//right wall
	{
		m_pos.x -= ballRect.right - wall.right+1;
		m_velocity.x = -m_velocity.x;
		//m_pos.x = 788.0f;
		//m_velocity.x *= (-1);
	}

	if (ballRect.top < wall.top)//top wall
	{
		m_pos.y += wall.top - ballRect.top;
		m_velocity.y = -m_velocity.y;
		//m_pos.y = 11.0f;
		//m_velocity.y *= (-1);
	}
	

	if (ballRect.bottom >= wall.bottom) //bottom
	{
		//m_pos.y = 589.0f;
		m_pos.y -= ballRect.bottom - wall.bottom+1;
		m_velocity.y = -m_velocity.y;

		//m_pos.y -= (m_pos.y - 600.0f);
		//m_velocity.y *= (-1);
	} 
}

RectF Ball::GetRect() const
{

	return RectF::FromCenter(m_pos, m_radius, m_radius);
}

void Ball::ShowRectF(Graphics& gfx) const
{

	gfx.DrawRectOutline(GetRect(), m_rectColor);
}
