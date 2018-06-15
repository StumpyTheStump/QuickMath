#pragma once
#include "Matrix3.h"
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

	void addForce(Vector3 force);
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;

private:
	aie::Texture* texture;
	SeekBehavior* seek;
};

