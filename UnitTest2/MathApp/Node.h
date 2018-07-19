#pragma once
#include <Vector2.h>
#include <vector>
#include "Edge.h"
struct Node
{
	Vector2 position;

	float gScore;
	Node* parent;

	std::vector<Edge>connections;
};
class Node
{
public:
	Node();
	~Node();

	void dijkstrasSearch();
};

