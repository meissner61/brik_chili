#include "Paddle.h"



void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRectPoint(m_pos.x, m_pos.y, m_pos.x + m_width, m_pos.y + m_height, m_color);
}

void Paddle::Move(Keyboard& kbd, float dt)
{
	if(kbd.KeyIsPressed(VK_LEFT))
		m_pos.x -= m_vel.x * dt;
	else if(kbd.KeyIsPressed(VK_RIGHT))
		m_pos.x += m_vel.x * dt;
}

void Paddle::CheckWallCollision(RectF wall)
{
	if (m_pos.x < wall.left)
	{
		m_pos.x += wall.left - m_pos.x;
	}

	else if (m_pos.x + m_width > wall.right)
	{
		m_pos.x =( m_pos.x - m_width) - (m_pos.x - wall.right + 1) ;
	}

}

void Paddle::CheckCollision(Ball& ball)
{
	//if (ball.rectangle.bottom >= m_rect.top)
	//{
	//	ball.m_velocity.y *= (-1);
	//}
}

