#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	union 
	{
		struct 
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};
		Vector4 axis[4];
		float data[4][4];

	};

	static const Matrix4 identity;

	Matrix4();
	Matrix4(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w);

	Vector4 & operator[](int index);
	const Vector4 & operator[](int index) const;

	Matrix4 operator*(const Matrix4 & other) const;
	Vector4 operator*(const Vector4 & vec) const;
	Vector4 operator=(const Matrix4 & other);
	explicit operator float*();

	Matrix4 transposed() const;

	void setScaled(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w);
	void setScaled(const Vector4 & vec);

	void scale(float a_x, float a_y, float a_z, float a_w, float b_x, float b_y, float b_z, float b_w, float c_x, float c_y, float c_z, float c_w, float d_x, float d_y, float d_z, float d_w);
	void scale(const Vector4 & vec);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);


	~Matrix4();
};

