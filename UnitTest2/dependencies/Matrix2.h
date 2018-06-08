#pragma once
#include "Vector2.h"
#include <math.h>

class Matrix2
{
public:
	union
	{
		struct
		{
			Vector2 xAxis;
			Vector2 yAxis;
		};
		Vector2 axis[2];
		float data[2][2];
	};

	static const Matrix2 identity;

	Matrix2();
	Matrix2(float a_x, float a_y, float b_x, float b_y);
	
	Vector2 & operator[](int index);
	const Vector2 & operator[](int index) const;

	Matrix2 operator*(const Matrix2 & other) const;
	Vector2 operator*(const Vector2 & vec);
	Vector2 operator=(const Matrix2 & other);
	explicit operator float*();

	Matrix2 transposed() const;

	void setScaled(float a_x, float a_y, float b_x, float b_y);

	void setScaled(const Vector2 & vec);

	void scale(float a_x, float a_y, float b_x, float b_y);

	void scale(const Vector2 & vec);

	void setRotate(float radians);

	void rotate(float radians);


	~Matrix2();
};


