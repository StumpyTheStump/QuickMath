#include "Graph.h"
#include <Renderer2D.h>
#include <stack>
#include <list>



Graph::Graph()
{
}

void Graph::AddNode(Node * node)
{
	nodes.push_back(node);
}

void Graph::ConnectNode(Node * a, Node * b, float cost)
{
	a->SetConnection(a, b, cost);
}

void Graph::draw(aie::Renderer2D * renderer)
{
	for (auto node : nodes)
	{
		for (auto it : node->GetConnections())
		{
			Edge* edge = it;
			renderer->setRenderColour(0.62, 0.62, 0.62, 1);
			renderer->drawLine(node->GetPosition().m_x, node->GetPosition().m_y, 
							   edge->GetNodeB()->GetPosition().m_x, edge->GetNodeB()->GetPosition().m_y, 1, 1.5f);
		}
		renderer->setRenderColour(0.62, 0.62, 0.62, 1);
		if (node->highlighted == true)
			renderer->setRenderColour(1, 0, 0, 1);

		renderer->drawBox(node->GetPosition().m_x, node->GetPosition().m_y, 10, 10, 0, 1);
	}
}

std::vector<Node*> Graph::GetNodes()
{
	return nodes;
}

std::vector<Node*> Graph::DFS(Node * startNode, Node * endNode)
{
	// Create a stack to store the nodes
	std::stack<Node*> nodeStack;
	// Push the first node on to the stack
	nodeStack.push(startNode);
	// While the stack is not empty
	while (!nodeStack.empty())
	{
		// Get the top node off the stack and remove it
		Node* currentNode = nodeStack.top();
		nodeStack.pop();
		currentNode->Visited(true);
		for (auto c : currentNode->GetConnections())
		{
			if (!c->GetNodeB()->CheckVisited())
			{
				nodeStack.push(c->GetNodeB());
				c->GetNodeB()->SetParent(currentNode);
			}
		}
	}

	std::vector<Node*> path;
	Node* currentPathNode = endNode;
	while (currentPathNode != NULL)
	{
		path.push_back(currentPathNode);
		currentPathNode = currentPathNode->GetParent();
	}
	
	return path;
}

std::vector<Node*> Graph::AStarSearch(Node * startNode, Node * endNode)
{
	// Set the parent node of all the nodes to null and set all the g-score to infinity
	for (auto n : nodes)
	{
		n->SetParent(nullptr);
		n->SetGScore(NULL);
		n->SetFScore(INFINITY);
	}
	// Set up priority queue
	std::list<Node*> priorityQueue;
	// Set the start node parent to nullptr
	startNode->SetParent(nullptr);
	// Set the start node gscore to 0
	startNode->SetGScore(0);
	// Push start node on to the priority queue
	priorityQueue.push_back(startNode);
	// While queue is not empty
	while (!priorityQueue.empty())
	{
		// Sort the priority queue based on the f-score
		priorityQueue.sort(Node::CompareFScore);
		// Get the current Node off the end of the queue
		Node* currentNode = priorityQueue.back();
		// Remove the current node from the queue
		priorityQueue.remove(currentNode);
		// Visited is equal to true
		currentNode->Visited(true);
		if (currentNode == endNode)
			break;
		// Loop through the current node edges
		for (auto e : currentNode->GetConnections())
		{
			// If end node is not traversed
			if (!e->GetNodeB()->CheckVisited())
			{
				// Heuristic score of current node to end node
				Vector2 dist = e->GetNodeB()->GetPosition() - endNode->GetPosition();
				float hScore = dist.magnitude();
				// Calculate current node’s g-score, the edge cost & heuristic of end node
				float cost = currentNode->GetGScore() + e->GetCost() + hScore;
				// If cost is less than the node connected to the edge
				if (cost < e->GetNodeB()->GetFScore())
				{
					// Set the parent connected to the edge to current node
					e->GetNodeB()->SetParent(currentNode);
					// Set the f-score connected to the edge to current node g-score, edge cost & heuristic score
					e->GetNodeB()->SetFScore(cost);
					// Push the target node to the queue
					priorityQueue.push_back(e->GetNodeB());
				}
			}	
		}
	}

	std::vector<Node*> path;
	// Setting the final node to the the current path node
	Node* currentPathNode = endNode;
	// Loop backwards to find the path
	while (currentPathNode != nullptr)
	{
		// Push the current node into the path
		path.push_back(currentPathNode);
		currentPathNode = currentPathNode->GetParent();
	}
	return path;
}



Graph::~Graph()
{
	for (auto& node : nodes)
	{
		delete node;
		node = nullptr;
	}
}
