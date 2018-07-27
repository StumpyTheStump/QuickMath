#pragma once
#include "Edge.h"
#include "Node.h"

namespace aie {
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	// Adds a node to the graph
	void AddNode(Node* node);
	// Connects the two nodes in the graph
	void ConnectNode(Node* a, Node* b, float cost);
	//Draw the nodes on the screen
	void draw(aie::Renderer2D* renderer);
	// Get the nodes
	std::vector<Node*> GetNodes();
	// Depth first search
	std::vector<Node*> DFS(Node* startNode, Node* endNode);
	// A* shortest path search
	std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);
	

	~Graph();
private:
	std::vector<Node*> nodes;
};

