#pragma once
#define PI 3.1415926535897932384626433832795
float DegtoRad(float degrees)
{
	float radians = (degrees * 180) / PI;
	return radians;
}

float RadtoDeg(float radians)
{
	float degrees = (radians * PI) / 180;
	return degrees;
}