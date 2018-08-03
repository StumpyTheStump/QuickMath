#include "PathfindingBehavior.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "Graph.h"
#include "StateMachine.h"
#include "IdleBehavior.h"



PathfindingBehavior::PathfindingBehavior()
{
}

PathfindingBehavior::PathfindingBehavior(std::vector<Node*> path)
{
	m_targetLocation = path;
	m_targetNode = m_targetLocation.back();
}

void PathfindingBehavior::update(Agent * agent, StateMachine * sm, float deltaTime)
{
	Vector2 desiredVel = m_targetNode->GetPosition() - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->AddForce(force);

	
	Vector2 dist = m_targetNode->GetPosition() - agent->position;
	float mag = dist.magnitude();
	// if agent reaches the nodes position 
	if (mag < 20.0f)
	{
		m_targetLocation.pop_back();
		if (m_targetLocation.empty())
		{
			sm->ChangeState(agent, new IdleBehavior());
			return;
		}
		m_targetNode = m_targetLocation.back();

	}
		// remove teh last node from the path

}

PathfindingBehavior::~PathfindingBehavior()
{
}
