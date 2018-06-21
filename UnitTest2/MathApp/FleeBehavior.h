#pragma once
#include "IBehavior.h"
class FleeBehavior : public IBehavior
{
public:
	FleeBehavior();
	FleeBehavior(Agent* target);
	void update(Agent* agent, float deltaTime);
	~FleeBehavior();

private:
	Agent*		m_target;
};

