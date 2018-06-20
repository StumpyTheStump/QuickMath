#pragma once
#include "IBehavior.h"
class SeekBehavior : public IBehavior
{
public:
	SeekBehavior();
	SeekBehavior(Agent* target);
	void update(Agent* agent, float deltaTime);
	~SeekBehavior();

	
private:
	Agent*		m_target;
};

