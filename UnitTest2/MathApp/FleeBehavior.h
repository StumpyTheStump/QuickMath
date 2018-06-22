#pragma once
#include "States.h"
class FleeBehavior : public State
{
public:
	FleeBehavior();
	FleeBehavior(Agent* target);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void initialise(Agent* agent);
	virtual void exit(Agent* agent);
	~FleeBehavior();

private:
	Agent*		m_target;
};

