#pragma once
class Vector3
{
public:
	union 
	{
		struct 
		{
			float m_x;
			float m_y;
			float m_z;
		};
		float data[3];
	};
	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator + (Vector3 other);
	Vector3 operator - (Vector3 other);
	Vector3 operator * (float scalar);
	friend Vector3 operator*(float scalar, Vector3 a_vec);
	Vector3 operator / (float scalar);
	Vector3 operator += (Vector3 other);
	Vector3 operator -= (Vector3 other);
	Vector3 operator *= (float scalar);
	Vector3 operator /= (float scalar);
	Vector3 operator = (Vector3 other);

	float operator[](int index);

	operator float*();
	operator const float* () const;

	float magnitude();
	Vector3 normalise();
	Vector3 cross(Vector3 other);
	float dot(const Vector3);

	~Vector3();
};


