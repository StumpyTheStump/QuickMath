#pragma once
#include <glm\vec2.hpp>
#include "SeekBehavior.h"
namespace aie
{
	class Renderer2D;
	class Texture;
}
class GameObject
{
public:
	GameObject();
	GameObject(GameObject* target, aie::Texture* texture);
	~GameObject();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	void addForce(glm::vec2 force);
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;

private:
	aie::Texture* texture;
	SeekBehavior* seek;
};

