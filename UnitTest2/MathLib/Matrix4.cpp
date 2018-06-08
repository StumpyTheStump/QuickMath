#include "Matrix4.h"
#include <math.h>



Matrix4::Matrix4()
{
	data[0][0] = 1; data[0][1] = 0; data[0][2] = 0; data[0][3] = 0;
	data[1][0] = 0; data[1][1] = 1; data[1][2] = 0; data[1][3] = 0;
	data[2][0] = 0; data[2][1] = 0; data[2][2] = 1; data[2][3] = 0;
	data[3][0] = 0; data[3][1] = 0; data[3][2] = 0; data[3][3] = 1;
}


const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);


Matrix4::Matrix4(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w)
{
	data[0][0] = a_x; data[0][1] = a_y; data[0][2] = a_z; data[0][3] = a_w;
	data[1][0] = b_x; data[1][1] = b_y; data[1][2] = b_z; data[1][3] = b_w;
	data[2][0] = c_x; data[2][1] = c_y; data[2][2] = c_z; data[2][3] = c_w;
	data[3][0] = d_x; data[3][1] = d_y; data[3][2] = d_z; data[3][3] = d_w;
}

Vector4 & Matrix4::operator[](int index)
{
	return axis[index];
}

const Vector4 & Matrix4::operator[](int index) const
{
	return axis[index];
}

Matrix4 Matrix4::operator*(const Matrix4 & other) const
{
	Matrix4 result;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.data[j][i] = data[0][i] * other.data[j][0] +
								data[1][i] * other.data[j][1] +
								data[2][i] * other.data[j][2] +
								data[3][i] * other.data[j][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator*(const Vector4 & vec) const
{
	Vector4 result;

	result.data[0] = data[0][0] * vec[0] +
					 data[1][0] * vec[1] +
					 data[2][0] * vec[2] +
					 data[3][0] * vec[3];

	result.data[1] = data[0][1] * vec[0] +
					 data[1][1] * vec[1] +
					 data[2][1] * vec[2] +
					 data[3][1] * vec[3];

	result.data[2] = data[0][2] * vec[0] +
					 data[1][2] * vec[1] +
					 data[2][2] * vec[2] +
					 data[3][2] * vec[3];

	result.data[3] = data[0][3] * vec[0] +
					 data[1][3] * vec[1] +
					 data[2][3] * vec[2] +
					 data[3][3] * vec[3];

	return result;
}

Vector4 Matrix4::operator=(const Matrix4 & other)
{
	return xAxis = other.xAxis, yAxis = other.yAxis, zAxis = other.zAxis, wAxis = other.wAxis;
}

Matrix4::operator float*()
{
	return &data[0][0];
}

Matrix4 Matrix4::transposed() const
{
	Matrix4 result;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.data[i][j] = data[j][i];
		}
	}

	return result;

}

void Matrix4::setScaled(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w)
{
	xAxis = { a_x, 0, 0, 0 };
	yAxis = { 0, b_y, 0, 0 };
	zAxis = { 0, 0, c_z, 0 };
	wAxis = { 0, 0, 0, d_w };
}

void Matrix4::setScaled(const Vector4 & vec)
{
	xAxis = { vec.m_x, 0, 0, 0 };
	yAxis = { 0, vec.m_y, 0, 0 };
	zAxis = { 0, 0, vec.m_z, 0 };
	wAxis = { 0, 0, 0, vec.m_w };
}

void Matrix4::scale(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w)
{
	Matrix4 m;
	m.setScaled(a_x, a_y, a_z, a_w, b_x, b_y, b_z, b_w, c_x, c_y, c_z, c_w, d_x, d_y, d_z, d_w);

	*this = *this * m;
}

void Matrix4::scale(const Vector4 & vec)
{
	Matrix4 m;
	m.setScaled(vec.m_x, 0, 0, 0, 0, vec.m_y, 0, 0, 0, 0, vec.m_z, 0, 0, 0, 0, vec.m_w);

	*this = *this * m;
}

void Matrix4::setRotateX(float radians)
{
	xAxis = {1, 0, 0, 0};
	yAxis = {0, cosf(radians), sinf(radians), 0};
	zAxis = {0, -sinf(radians), cosf(radians), 0};
	wAxis = {data[3][0], data[3][1], data[3][2], data[3][3] };
}

void Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { sinf(radians), 0, cosf(radians), 0 };
	wAxis = { data[3][0], data[3][1], data[3][2], data[3][3] };
}

void Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0, 0 };
	yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0, 0, 1, 0 };
	wAxis = { data[3][0], data[3][1], data[3][2], data[3][3] };
}

void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

Matrix4::~Matrix4()
{
}
