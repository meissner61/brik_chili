#include "Vec2.h"

Vec2::Vec2(float x, float y)
	:
	m_x(x),
	m_y(y)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(m_x + rhs.m_x, m_y+ rhs.m_y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
// two ways to return this operation
	/*
	m_x += rhs.m_x;
	m_y += rhs.m_y;

	return *this;
	*/

//since we already defined addition we can do:
	/*
	*this = *this + rhs;
	return *this;
	*/
// But because assignment returns a reference to the self object we can do(Tutorial 19, 15:20):

	return *this = *this + rhs;

}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(m_x * rhs,m_y * rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(m_x - rhs.m_x, m_y - rhs.m_y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

float Vec2::GetLength() const
{

	return sqrt( GetLengthSquared() );
}

float Vec2::GetLengthSquared() const
{
	return m_x*m_x + m_y*m_y;
}

Vec2& Vec2::Normalize()
{
	float len = GetLength();
	return Vec2(m_x * (1 / len), m_y * (1 / len));
}

Vec2 Vec2::GetNormalized() const
{
	float len = GetLength();
	//I keep making this mistake but use the vector as a whole entity!!
	//return Vec2(m_x * (1 / len), m_y * (1 / len)); //<------BAD

	if (len != 0.0f)
	{
		return *this * (1 / len);
	}

	return *this;
	
}
