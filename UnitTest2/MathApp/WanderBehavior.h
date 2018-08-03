#pragma once
#include "States.h"
class WanderBehavior : public State
{
public:
	WanderBehavior();
	WanderBehavior(Agent* target, float wanderDistance, float wanderRadius, float jitterAmount);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void initialise(Agent* agent);
	virtual void exit(Agent* agent);
	~WanderBehavior();

private:
	float		m_wanderDist;
	float		m_wanderRad;
	float		m_jitterAmount;
	Vector2		randomVec;
	Agent*		m_target;
};

