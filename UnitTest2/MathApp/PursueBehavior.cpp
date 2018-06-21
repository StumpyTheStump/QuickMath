#include "PursueBehavior.h"



PursueBehavior::PursueBehavior()
{
	m_target = nullptr;
}

PursueBehavior::PursueBehavior(Agent * target)
{
	m_target = target;
}

void PursueBehavior::update(Agent * agent, float deltaTime)
{
	Vector3 desiredVal = (m_target->position + m_target->velocity * 10) - agent->position;
	desiredVal.normalise();
	desiredVal = desiredVal * 100;
	Vector3 force = desiredVal - agent->velocity;
	agent->AddForce(force);
}


PursueBehavior::~PursueBehavior()
{
	delete m_target;
}
