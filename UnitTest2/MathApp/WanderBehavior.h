#pragma once
#include "IBehavior.h"
class WanderBehavior : IBehavior
{
public:
	WanderBehavior();
	WanderBehavior(Agent* target);
	void update(Agent* agent, float deltaTime);
	~WanderBehavior();

private:
	Agent*		m_target;
};

