#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "StateMachine.h"



SeekBehavior::SeekBehavior()
{
	m_target = nullptr;
}

SeekBehavior::SeekBehavior(Agent * target)
{
	m_target = target;
}

void SeekBehavior::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector3 desiredVel = m_target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector3 force = desiredVel - agent->velocity;
	agent->AddForce(force);

	Vector3 dist = m_target->position - agent->position;
	float mag = dist.magnitude();
	if (mag > 300.0f)
		sm->ChangeState(agent, new WanderBehavior(m_target, 0.0f, 100.0f, 20.0f));
}

void SeekBehavior::initialise(Agent * agent)
{
}

void SeekBehavior::exit(Agent * agent)
{
}


SeekBehavior::~SeekBehavior()
{
	delete m_target;
}