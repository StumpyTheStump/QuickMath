#pragma once
#include "IBehavior.h"
#include "States.h"
class StateMachine : public IBehavior
{
public:
	StateMachine();
	virtual void update(Agent* agent, float deltaTime);
	void ChangeState(Agent* agent, State* newState);
	State* GetCurrentState();
	State* GetPrevState();
	~StateMachine();

private:
	State*		currentState;
	State*		prevState;
};

