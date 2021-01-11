#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
	:
	x(x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y+ rhs.y);
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
// two ways to return this operation
	/*
	x += rhs.x;
	y += rhs.y;

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
	return Vec2(x * rhs,y * rhs);
}

Vec2& Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
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
	return x*x + y*y;
}

Vec2& Vec2::Normalize()
{
	
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{
	float len = GetLength();
	//I keep making this mistake but use the vector as a whole entity!!
	//return Vec2(x * (1 / len), y * (1 / len)); //<------BAD

	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}

	return *this;
	
}
