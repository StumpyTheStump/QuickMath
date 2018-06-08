#include "SpriteObject.h"

void SpriteObject::onDraw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
}
