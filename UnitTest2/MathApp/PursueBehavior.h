#pragma once
#include "IBehavior.h"
class PursueBehavior : public IBehavior
{
public:
	PursueBehavior();
	PursueBehavior(Agent* target);
	void update(Agent* agent, float deltaTime);
	~PursueBehavior();

private:
	Agent*		m_target;
};

