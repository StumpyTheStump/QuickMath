#pragma once
#include "Vector3.h"
#include <vector>
namespace aie
{
	class Renderer2D;
	class Texture;
}
class IBehavior;

class Agent
{
public:
	Agent();
	Agent(aie::Texture* texture, Vector3 position);
	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	void AddForce(Vector3 force);
	void AddBehavior(IBehavior* behavior);
	~Agent();
	Vector3 position;
	Vector3 acceleration;
	Vector3 velocity;
protected:
	aie::Texture* texture;
	std::vector<IBehavior*> m_behaviors;
};

