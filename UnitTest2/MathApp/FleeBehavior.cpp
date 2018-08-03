#include "FleeBehavior.h"



FleeBehavior::FleeBehavior()
{
	m_target = nullptr;
}

FleeBehavior::FleeBehavior(Agent * target)
{
	m_target = target;
}

void FleeBehavior::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 desiredVal = m_target->position - agent->position;
	desiredVal.normalise();
	desiredVal = desiredVal * -100.0f;
	Vector2 force = desiredVal - agent->velocity;
	agent->AddForce(force);
}

void FleeBehavior::initialise(Agent * agent)
{
}

void FleeBehavior::exit(Agent * agent)
{
}

FleeBehavior::~FleeBehavior()
{
	delete m_target;
}
