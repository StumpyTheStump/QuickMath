#pragma once
#include "States.h"
#include <list>

class Graph;
class Node;

class PathfindingBehavior : public State
{
public:
	PathfindingBehavior();
	PathfindingBehavior(std::vector<Node*> path);
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void initialise(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~PathfindingBehavior();

private:
	std::vector<Node*> m_targetLocation;
	Node* m_targetNode = nullptr;
};

