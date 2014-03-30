#ifndef COMPONENT_H
#define COMPONENT_H

#include "GameObject.h"

class GameObject;

class Component
{
public:
	virtual ~Component() {}

	void SetGameObject(GameObject *go) { m_gameObject = go; }

protected:
	GameObject *m_gameObject;
};

#endif