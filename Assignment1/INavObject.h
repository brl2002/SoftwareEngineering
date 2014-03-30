#ifndef INAVOBJECT_H
#define INAVOBJECT_H

#include "Sprite.h"

class INavObject
{
public:
	virtual ~INavObject() {}

	virtual void Update(float dt) = 0;

	virtual void Draw() = 0;

	virtual void Enable() = 0;

	virtual void Disable() = 0;

protected:
	Sprite *m_sprite;
};

#endif