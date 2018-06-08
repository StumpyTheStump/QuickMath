#include "Vector2.h"
#include <math.h>



Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{
}

Vector2 Vector2::operator+(Vector2 other)
{
	return { m_x + other.m_x, m_y + other.m_y };
}

Vector2 Vector2::operator-(Vector2 other)
{
	return { m_x - other.m_x, m_y - other.m_y };
}

Vector2 Vector2::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar};
}

Vector2 Vector2::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar };
}

Vector2 Vector2::operator+=(Vector2 other)
{
	return { m_x += other.m_x, m_y += other.m_y };
}

Vector2 Vector2::operator-=(Vector2 other)
{
	return { m_x -= other.m_x, m_y -= other.m_y };
}

Vector2 Vector2::operator*=(float scalar)
{
	return { m_x *= scalar, m_y *= scalar };
}

Vector2 Vector2::operator/=(float scalar)
{
	return { m_x /= scalar, m_y /= scalar };
}

Vector2 Vector2::operator=(const Vector2 & other)
{
	return { m_x = other.m_x, m_y = other.m_y };
}

float Vector2::operator [](int index)
{
	return data[index];
}

Vector2::operator float* ()
{
	return data;
}

Vector2::operator const float*() const
{ 
	return data; 
}

float Vector2::magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y);
}

Vector2 Vector2::normalise()
{
	float m = sqrt(m_x * m_x + m_y * m_y);
	return { m_x /= m, m_y /= m };
}

float Vector2::dot(const Vector2 other)
{
	return m_x * other.m_x + m_y * other.m_y;
}


Vector2::~Vector2()
{
}


Vector2 operator*(float scalar, Vector2 a_vec)
{
	return Vector2(scalar * a_vec.m_x, scalar*a_vec.m_y);
}
