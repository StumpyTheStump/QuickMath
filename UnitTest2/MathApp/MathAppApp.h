#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"
class Agent;
class MathAppApp : public aie::Application {
public:

	MathAppApp();
	virtual ~MathAppApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	void addForce(Vector3 force);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	SpriteObject		m_tank, m_turret;
	Agent*				m_AI;
	Vector3				m_velocity;
	Vector3				m_acceleration;
	float				m_speed;
};