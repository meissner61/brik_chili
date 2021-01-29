#include "Paddle.h"



void Paddle::Draw(Graphics& gfx) const
{
	const RectF rect = GetRect();
	gfx.DrawRectOutline(rect, m_color);
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

void Paddle::TopCollision(Ball& ball)
{
	const RectF ballRect = ball.GetRect();
	const RectF rect = GetRect();

	//if (ballRect.bottom > rect.top && ballRect.right > rect.left && ballRect.left < rect.right)
	//{
	//	ball.ReboundY();
	//}

	if (ballRect.Overlapping(rect))
	{
		ball.ReboundY();
	}
}

RectF Paddle::GetRect() const
{
	return RectF(m_pos,m_width,m_height);
}

