#include "FleeBehavior.h"



FleeBehavior::FleeBehavior()
{
	m_target = nullptr;
}

FleeBehavior::FleeBehavior(Agent * target)
{
	m_target = target;
}

void FleeBehavior::update(Agent * agent, float deltaTime)
{
	Vector3 desiredVal = m_target->position - agent->position;
	desiredVal.normalise();
	desiredVal = desiredVal * -100.0f;
	Vector3 force = desiredVal - agent->velocity;
	agent->AddForce(force);
}


FleeBehavior::~FleeBehavior()
{
	delete m_target;
}
