#pragma once
#include <Vector2.h>
#include <vector>
class Edge;

class Node
{
public:
	Node();
	// Value for the node
	void SetPosition(Vector2 position);
	Vector2 GetPosition();

	// A flag to check if the node has visited already
	void SetVisited(bool visited);
	bool GetVisited();

	// Add connections to the node
	void AddConnections(Node* node, Node* target, float cost);
	std::vector<Edge*> GetConnections();

	// Set the parent
	void SetParent(Node* node);
	Node* GetParent();

	// Set the g-score
	void SetGScore(float gScore);
	float GetGScore();

	static bool CompareGScore(Node* a, Node* b);

	~Node();

private:
	Vector2					m_position;
	bool					m_isVisited;
	Node*					m_parent;
	float					m_gScore;
	std::vector<Edge*>		m_connections;
};

