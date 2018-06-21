#pragma once
#include "IBehavior.h"
class EvadeBehavior : public IBehavior
{
public:
	EvadeBehavior();
	EvadeBehavior(Agent* target);
	void update(Agent* agent, float deltaTime);
	~EvadeBehavior();

private:
	Agent*		m_target;
};

