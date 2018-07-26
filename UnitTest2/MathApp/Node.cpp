#include "Node.h"



Node::Node()
{
}

void Node::SetPosition(Vector2 position)
{
}

Vector2 Node::GetPosition()
{
	return Vector2();
}

void Node::SetVisited(bool visited)
{
}

bool Node::GetVisited()
{
	return false;
}

void Node::AddConnections(Node * node, Node * target, float cost)
{
}

std::vector<Edge*> Node::GetConnections()
{
	return std::vector<Edge*>();
}

void Node::SetParent(Node * node)
{
}

Node * Node::GetParent()
{
	return nullptr;
}

void Node::SetGScore(float gScore)
{
}

float Node::GetGScore()
{
	return 0.0f;
}

bool Node::CompareGScore(Node * a, Node * b)
{
	return false;
}


Node::~Node()
{
}


