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
	if (m_pos.x - m_radius <= wall.left)//left wall
	{
		m_pos.x += wall.left - GetRect().left;
		m_velocity.x = -m_velocity.x;
		//m_pos.x = 11.0f;
		//m_velocity.x *= (-1);
	}

	if (m_pos.x + m_radius >= 799.0f)//right wall
	{
		m_pos.x -= GetRect().right - wall.right;
		m_velocity.x = -m_velocity.x;
		//m_pos.x = 788.0f;
		//m_velocity.x *= (-1);
	}

	if (m_pos.y - m_radius <= 1.0f)//top wall
	{
		m_pos.y += wall.top - GetRect().top;
		m_velocity.y = -m_velocity.y;
		//m_pos.y = 11.0f;
		//m_velocity.y *= (-1);
	}
	

	if (m_pos.y + m_radius >= 599.0f) //bottom
	{
		//m_pos.y = 589.0f;
		m_pos.y -= (GetRect().bottom - wall.bottom)+1;
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
