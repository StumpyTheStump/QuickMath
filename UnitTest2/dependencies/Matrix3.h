#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	union {
		struct 
		{
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};
		Vector3 axis[3];
		float data[3][3];
		Vector3 translation;
	};
	
	static const Matrix3 identity;

	Matrix3();

	Matrix3(float a_x, float a_y, float a_z, float b_x, float b_y, float b_z, float c_x, float c_y, float c_z);

	Vector3 & operator[](int index);
	const Vector3 & operator[](int index) const;

	Matrix3 operator*(const Matrix3 & other) const;
	Vector3 operator*(const Vector3 & vec) const;
	Vector3 operator=(const Matrix3 & other);
	explicit operator float*();

	Matrix3 transposed() const;

	void setScaled(float x, float y, float z);
	void setScaled(const Vector3 & vec);

	void scale(float x, float y, float z);
	void scale(const Vector3 & vec);

	void translate(float x, float y, float z);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);



	~Matrix3();
};

