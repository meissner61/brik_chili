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
	gfx.DrawCircle(m_pos.x, m_pos.y, m_radius, m_color);
}

void Ball::Update()
{
	m_pos += m_velocity;
}

void Ball::CheckCollision()
{
	if (m_pos.x - m_radius <= 0.0f)//left
	{
		//m_pos.x -= 0.0f - m_pos.x;
		m_pos.x = 11.0f;
		m_velocity.x *= (-1);
	}

	if (m_pos.x + m_radius >= 799.0f)//right
	{

		m_pos.x = 788.0f;
		m_velocity.x *= (-1);
	}

	if (m_pos.y - m_radius <= 1.0f)//top
	{
		m_pos.y = 11.0f;
		//m_pos.y += (0.0f - m_pos.y);
		m_velocity.y *= (-1);
	}
	
	/*Something weird is going on at the bottom of the screen that anytime
	It gets greater than the bottom it automatically throws a dword exception
	so for now I just have the ball rebound 20 pixels above the screen
	Because if the speed is too fast it goes out of bounds quickly and
	throws said exception*/

	if (m_pos.y + m_radius >= 599.0f) //bottom
	{
		m_pos.y = 589.0f;
		//m_pos.y -= (m_pos.y - 600.0f);
		m_velocity.y *= (-1);
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
