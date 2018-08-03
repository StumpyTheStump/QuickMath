#include "WanderBehavior.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "StateMachine.h"
#include "SeekBehavior.h"

WanderBehavior::WanderBehavior()
{
}

WanderBehavior::WanderBehavior(Agent * target, float wanderDistance, float wanderRadius, float jitterAmount)
{
	m_wanderDist = wanderDistance;
	m_wanderRad = wanderRadius;
	m_jitterAmount = jitterAmount;

	randomVec = Vector2(rand() % (int)m_jitterAmount, rand() % (int)m_jitterAmount);
	m_target = target;
}


void WanderBehavior::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	// set the sphere based on the wander_radius
	glm::vec2 circle = glm::circularRand(m_wanderRad);
	// create a new Target by adding the rand vec and circle
	Vector2 newTarget = Vector2(randomVec.m_x + circle.x, randomVec.m_y + circle.y);
	// normalise the new target
	newTarget.normalise();
	Vector2 normalisedTarget = newTarget;
	// project it back on the to the sphere
	Vector2 targetOnSphere = normalisedTarget * m_wanderRad;
	// move in straight line towards the target on the sphere
	targetOnSphere.normalise();
	Vector2 force = targetOnSphere;
	force = force * 50.0f;

	agent->AddForce(force);

	Vector2 dist = m_target->position - agent->position;
	float mag = dist.magnitude();
	if (mag < 300.0f)
		sm->ChangeState(agent, new SeekBehavior(m_target));
}

void WanderBehavior::initialise(Agent * agent)
{
}

void WanderBehavior::exit(Agent * agent)
{
}

WanderBehavior::~WanderBehavior()
{
}
