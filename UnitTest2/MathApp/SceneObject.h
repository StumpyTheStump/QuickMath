#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include <vector>
class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();

	SceneObject* getParent() const { return m_parent; }
	size_t childCount() const { return m_children.size(); }
	SceneObject* getChild(unsigned int index) const
	{
		return m_children[index];
	}

	void addChild(SceneObject * child);
	void removeChild(SceneObject * child);

	virtual void onUpdate(float deltaTime);
	virtual void onDraw(aie::Renderer2D * renderer);

	void update(float deltaTime);

	void draw(aie::Renderer2D * renderer);

	const Matrix3 & getLocalTransform() const;

	const Matrix3 & getGlobalTransform() const;

	void updateTransform();

	void setPosition(float x, float y);

	void setRotate(float radians);

	void setScale(float width, float height);

	void translate(float x, float y);

	void rotate(float radians);

	void scale(float width, float height);

protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;
};

