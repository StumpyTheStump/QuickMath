#include "Matrix3.h"
#include <math.h>



Matrix3::Matrix3()
{
		data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
		data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
		data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
}


const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);


Matrix3::Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z)
{
	data[0][0] = a_x; data[0][1] = a_y; data[0][2] = a_z;
	data[1][0] = b_x; data[1][1] = b_y; data[1][2] = b_z;
	data[2][0] = c_x; data[2][1] = c_y; data[2][2] = c_z;
}

Vector3& Matrix3::operator[] (int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator[] (int index) const 
{
	return axis[index];
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			result.data[j][i] = data[0][i] * other.data[j][0] +
								data[1][i] * other.data[j][1] +
								data[2][i] * other.data[j][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator*(const Vector3& vec) const
{
	Vector3 result;

	result.data[0] = data[0][0] * vec[0] + 
					 data[1][0] * vec[1] + 
					 data[2][0] * vec[2];

	result.data[1] = data[0][1] * vec[0] +
					 data[1][1] * vec[1] +
					 data[2][1] * vec[2];

	result.data[2] = data[0][2] * vec[0] +
		             data[1][2] * vec[1] +
					 data[2][2] * vec[2];

	return result;
}

Vector3 Matrix3::operator=(const Matrix3& other)
{
	return xAxis = other.xAxis, yAxis = other.yAxis, zAxis = other.zAxis;
}

Matrix3::operator float*()
{
	return &data[0][0];
}

Matrix3 Matrix3::transposed() const
{
	Matrix3 result;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			result.data[i][j] = data[j][i];
		}
	}

	return result;

}

void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };
}

void Matrix3::setScaled(const Vector3& vec)
{
	xAxis = { vec.m_x, 0, 0 };
	yAxis = { 0, vec.m_y, 0 };
	zAxis = { 0, 0, vec.m_z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}

void Matrix3::scale(const Vector3& vec)
{
	Matrix3 m;
	m.setScaled(vec.m_x, vec.m_y, vec.m_z);

	*this = *this * m;
}

void Matrix3::translate(float x, float y, float z)
{
	axis[2] += {x, y, z};
}

void Matrix3::setRotateX(float radians)
{
	xAxis = {	1,	       0,			   0	  };
	yAxis = {	0,   cosf(radians), sinf(radians) };
	zAxis = {	0,  -sinf(radians), cosf(radians) };
}

void Matrix3::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = {	   0,		 1,	     0		   };
	zAxis = { sinf(radians), 0, cosf(radians)  };
}

void Matrix3::setRotateZ(float radians)
{
	xAxis = {  cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0, 1 };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

Matrix3::~Matrix3()
{
}
