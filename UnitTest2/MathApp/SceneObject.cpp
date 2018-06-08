#include "SceneObject.h"
#include <assert.h>


SceneObject::SceneObject()
{
}


void SceneObject::addChild(SceneObject*child)
{
	assert(child->m_parent == nullptr);

	child->m_parent = this;

	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject*child)
{
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	if (iter != m_children.end())
	{
		m_children.erase(iter);

		child->m_parent = nullptr;
	}
}

void SceneObject::onUpdate(float deltaTime)
{
}

void SceneObject::onDraw(aie::Renderer2D * renderer)
{
}

void SceneObject::update(float deltaTime)
{
	onUpdate(deltaTime);

	for (auto child : m_children)
		child->update(deltaTime);
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	onDraw(renderer);
	for (auto child : m_children)
		child->draw(renderer);

}

const Matrix3& SceneObject::getLocalTransform() const
{
	return m_localTransform;
}

const Matrix3& SceneObject::getGlobalTransform() const
{
	return m_globalTransform;
}

void SceneObject::updateTransform()
{
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform* m_localTransform;
	else
		m_globalTransform = m_localTransform;

	for (auto child : m_children)
		child->updateTransform();
}

void SceneObject::setPosition(float x, float y)
{
	m_localTransform[2] = { x, y, 1 };
	updateTransform();
}

void SceneObject::setRotate(float radians)
{
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void SceneObject::setScale(float width, float height)
{
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

void SceneObject::translate(float x, float y)
{
	m_localTransform.translate(x, y, 1);
	updateTransform();
}

void SceneObject::rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void SceneObject::scale(float width, float height)
{
	m_localTransform.scale(width, height, 1);
	updateTransform();
}

SceneObject::~SceneObject()
{
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	for (auto child : m_children)
		child->m_parent = nullptr;
}


