#include "EvadeBehavior.h"



EvadeBehavior::EvadeBehavior()
{
	m_target = nullptr;
}

EvadeBehavior::EvadeBehavior(Agent * target)
{
	m_target = target;
}

void EvadeBehavior::update(Agent * agent, float deltaTime)
{
	Vector2 desiredVal = agent->position - (m_target->position + m_target->velocity * 10);
	desiredVal.normalise();
	desiredVal = desiredVal * 100;
	Vector2 force = desiredVal - agent->velocity;
	agent->AddForce(force);
}


EvadeBehavior::~EvadeBehavior()
{
	delete m_target;
}
