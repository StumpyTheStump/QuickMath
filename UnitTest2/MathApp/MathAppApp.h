#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"
#include <vector>
class Agent;
class StateMachine;
class Graph;
class MathAppApp : public aie::Application {
public:

	MathAppApp();
	virtual ~MathAppApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	void addForce(Vector3 force);

	void SetGraph();

protected:

	aie::Renderer2D*		m_2dRenderer;
	aie::Font*				m_font;
	SpriteObject			m_tank, m_turret;
	StateMachine*			m_fsm;
	StateMachine*			m_fsm2;
	std::vector<Agent*>		m_agents;
	Vector3					m_velocity;
	Vector3					m_acceleration;
	float					m_speed;
	Graph*					m_graph;
};