#include "SeekBehavior.h"



SeekBehavior::SeekBehavior()
{
	m_target = nullptr;
}

SeekBehavior::SeekBehavior(Agent * target)
{
	m_target = target;
}

void SeekBehavior::update(Agent * agent, float deltaTime)
{
	Vector3 desiredVel = m_target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector3 force = desiredVel - agent->velocity;
	agent->AddForce(force);
}

SeekBehavior::~SeekBehavior()
{
	delete m_target;
}