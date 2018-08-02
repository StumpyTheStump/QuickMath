#include "PathfindingBehavior.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "Graph.h"
#include "StateMachine.h"



PathfindingBehavior::PathfindingBehavior()
{
	m_targetLocation = nullptr;
}

PathfindingBehavior::PathfindingBehavior(std::list<Node*> targetLocation)
{
}


void PathfindingBehavior::update(Agent * agent, float deltaTime)
{
	Vector3 desiredVel = m_targetLocation->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector3 force = desiredVel - agent->velocity;
	agent->AddForce(force);
}

void PathfindingBehavior::initialise(Agent * agent)
{
}

void PathfindingBehavior::exit(Agent * agent)
{
}


PathfindingBehavior::~PathfindingBehavior()
{
	delete m_targetLocation;
}
