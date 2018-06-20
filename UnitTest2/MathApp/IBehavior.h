#pragma once
#include "Agent.h"
class IBehavior
{
public:
	virtual void update(Agent* agent, float deltaTime) = 0;
};

