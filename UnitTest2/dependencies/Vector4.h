#pragma once
class Vector4
{
public:
	union
	{
		struct
		{
			float m_x;
			float m_y;
			float m_z;
			float m_w;
		};
		float data[4];
	};
	Vector4();
	Vector4(float x, float y, float z, float w);

	Vector4 operator + (Vector4 other);
	Vector4 operator - (Vector4 other);
	Vector4 operator * (float scalar);
	friend Vector4 operator*(float scalar, Vector4 a_vec);
	Vector4 operator / (float scalar);
	Vector4 operator += (Vector4 other);
	Vector4 operator -= (Vector4 other);
	Vector4 operator *= (float scalar);
	Vector4 operator /= (float scalar);
	Vector4 operator = (Vector4 other);

	float operator[](int index);

	operator float*();
	operator const float* () const;

	float magnitude();
	Vector4 normalise();
	Vector4 cross(Vector4 other);
	float dot(const Vector4);
	~Vector4();
};

