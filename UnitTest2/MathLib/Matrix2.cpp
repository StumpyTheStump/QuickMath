#include "Matrix2.h"
#include <ostream>



Matrix2::Matrix2()
{
	data[0][0] = 1; data[0][1] = 0;
	data[1][0] = 0; data[1][1] = 1;
}

const Matrix2 Matrix2::identity = Matrix2(1, 0, 0, 1);

Matrix2::Matrix2(float a_x, float a_y, float b_x, float b_y)
{
	data[0][0] = a_x; data[0][1] = a_y;
	data[1][0] = b_x; data[1][1] = b_y;
}

Vector2& Matrix2::operator[] (int index)
{
	return axis[index];
}

const Vector2& Matrix2::operator[] (int index) const
{
	return axis[index];
}

Matrix2 Matrix2::operator * (const Matrix2& other) const
{

	Matrix2 result;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			result.data[j][i] = data[0][i] * other.data[j][0] +
								data[1][i] * other.data[j][1];
		}
	}
	return result;
}

Vector2 Matrix2::operator* (const Vector2& vec) 
{
	Vector2 result;

	result.data[0] = data[0][0] * vec[0] +
					 data[1][0] * vec[1];

	result.data[1] = data[0][1] * vec[0] +
					 data[1][1] * vec[1];
	return result;
}

Vector2 Matrix2::operator=(const Matrix2 & other)
{
	return xAxis = other.xAxis, yAxis = other.yAxis;
}

Matrix2::operator float*()
{
	return &data[0][0];
}

Matrix2 Matrix2::transposed() const
{
	Matrix2 result;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			result.data[i][j] = data[j][i];
		}
	}
	return result;
}



void Matrix2::setScaled(float a_x, float a_y, float b_x, float b_y)
{
	xAxis = { a_x, 0 };
	yAxis = { 0, b_y };
}

void Matrix2::setScaled(const Vector2& vec)
{
	xAxis = { vec.m_x, 0 };
	yAxis = { 0, vec.m_y };
}

void Matrix2::scale(float a_x, float a_y, float b_x, float b_y)
{
	Matrix2 m;
	m.setScaled(a_x, a_y, b_x, b_y);

	*this = *this * m;
}

void Matrix2::scale(const Vector2& vec)
{
	Matrix2 m;
	m.setScaled(vec.m_x, 0, 0, vec.m_y);

	*this = *this * m;
}

void Matrix2::setRotate(float radians)
{
	xAxis = { cosf(radians), sinf(radians) };
	yAxis = { -sinf(radians), cosf(radians) };
}

void Matrix2::rotate(float radians)
{
	Matrix2 m;
	m.setRotate(radians);

	*this = *this * m;
}



Matrix2::~Matrix2()
{
}
