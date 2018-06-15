#pragma once
class GameObject;
class SeekBehavior
{
public:
	SeekBehavior();
	SeekBehavior(GameObject* target);
	~SeekBehavior();

	void update(GameObject* agent, float deltaTime);
	GameObject * target;
private:
};

