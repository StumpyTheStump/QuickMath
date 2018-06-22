#pragma once
#include "States.h"
class SeekBehavior : public State
{
public:
	SeekBehavior();
	SeekBehavior(Agent* target);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void initialise(Agent* agent);
	virtual void exit(Agent* agent);
	~SeekBehavior();

	
private:
	Agent*		m_target;
};

