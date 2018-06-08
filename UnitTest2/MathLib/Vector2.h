#pragma once
class Vector2
{
public:
	union 
	{
		struct 
		{
			float m_x;
			float m_y;
		};
		float data[2];
	};
	Vector2();
	Vector2(float x, float y);

	Vector2 operator + (Vector2 other);
	Vector2 operator - (Vector2 other);
	Vector2 operator * (float scalar);
	friend Vector2 operator *(float scalar, Vector2 a_vec);
	Vector2 operator / (float scalar);
	Vector2 operator += (Vector2 other);
	Vector2 operator -= (Vector2 other);
	Vector2 operator *= (float scalar);
	Vector2 operator /= (float scalar);
	Vector2 operator=(const Vector2 & other);

	float operator[](int index);

	operator float*();
	operator const float*() const;
	
	float magnitude();
	Vector2 normalise();
	float dot(const Vector2);
	

	~Vector2();
};

