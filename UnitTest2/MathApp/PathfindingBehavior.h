#pragma once
#include "States.h"
#include <list>

class Graph;

class PathfindingBehavior : public State
{
public:
	PathfindingBehavior();
	PathfindingBehavior(std::list<Node*> targetLocation);
	virtual void update(Agent* agent, float deltaTime);
	virtual void initialise(Agent* agent);
	virtual void exit(Agent* agent);
	~PathfindingBehavior();

private:
	Node* m_targetLocation;
};

