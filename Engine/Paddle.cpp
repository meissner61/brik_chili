#include "Paddle.h"

Paddle::Paddle(Vec2& position,Ball& ball)
	:
	m_pos(position)
{
}

void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRectPoint(m_pos.x, m_pos.y, m_pos.x + m_width, m_pos.y + m_height, m_color);
}

void Paddle::Move(int direction)
{
	m_pos += m_vel* direction;

}

void Paddle::CheckCollision(Ball& ball)
{
	//if (ball.rectangle.bottom >= m_rect.top)
	//{
	//	ball.m_velocity.y *= (-1);
	//}
}

