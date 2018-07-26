#pragma once
class Node;

class Edge
{
public:
	Edge();
	// Setting the target node
	void SetNode(Node* node);
	Node* GetNode();

	// Cost of the edge
	void SetCost(float cost);
	float GetCost();

	~Edge();
private:
	Node * target;
	float cost;
};

