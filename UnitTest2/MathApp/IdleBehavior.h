#pragma once
#include "States.h"

class IdleBehavior : public State
{
public:
	IdleBehavior();
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void initialise(Agent* agent);
	virtual void exit(Agent* agent);
	~IdleBehavior();
};

