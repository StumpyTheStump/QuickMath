#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"

class MathAppApp : public aie::Application {
public:

	MathAppApp();
	virtual ~MathAppApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	void moveForward(float amount);
	void turnLeft(float rotate);
	void turnRight(float rotate);
	void addForce(Vector3 force);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	SpriteObject		m_tank, m_turret;
	Vector3				m_velocity;
	Vector3				m_acceleration;
	Vector3				m_position;
	float				m_speed;
	float				m_rotation;
	float				m_rotationSpeed;
	Matrix3				m_local;
	Matrix3				m_world;
};