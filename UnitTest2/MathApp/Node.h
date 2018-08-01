#pragma once
#include <Vector2.h>
#include <vector>
class Edge;

class Node
{
public:
	Node();
	// Connects nodes
	void SetConnection(Node* a, Node* b, float cost);
	std::vector<Edge*> GetConnections();
	// Position of the node
	Vector2 GetPosition();
	void SetPosition(Vector2 pos);
	// Check if the node has been visited
	void Visited(bool isVisited);
	bool CheckVisited();
	// Set the parent node
	void SetParent(Node* parent);
	Node* GetParent();
	// GScore for the node
	void SetGScore(float score);
	float GetGScore();
	// FScore for the node
	void SetFScore(float score);
	float GetFScore();

	static bool CompareGScore(Node* a, Node* b);
	static bool CompareFScore(Node* a, Node* b);

	bool highlighted;

	~Node();

private:
	
	bool					visited;
	float					gScore;
	float					fScore;
	Vector2					position;
	Node*					parent;
	std::vector<Edge*>		connections;
};

