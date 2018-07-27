#pragma once
class Node;

class Edge
{
public:
	Edge();
	// Setting the target node
	Node* GetNodeB();
	void SetNodeB(Node* node);
	// Cost of the edge
	float GetCost();
	void SetCost(float cost);

	~Edge();
private:
	Node* nodeB;
	float cost;
};

