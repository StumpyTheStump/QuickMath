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
	Vector2 desiredVal = (m_target->position + m_target->velocity * 10) - agent->position;
	desiredVal.normalise();
	desiredVal = desiredVal * 100;
	Vector2 force = desiredVal - agent->velocity;
	agent->AddForce(force);
}


PursueBehavior::~PursueBehavior()
{
	delete m_target;
}
