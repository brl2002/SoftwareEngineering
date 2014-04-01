#ifndef PHYSICS2D_H
#define PHYSICS2D_H

#include "GameObject.h"
#include <vector>

class GameObject;

class Physics2D
{
public:
	static Physics2D& getInstance()
	{
		static Physics2D instance;

		return instance;
	}

	void addGameObject(GameObject* gameObject);

	void Update(float deltaTime);

	void DebugDraw();

	void Clean(GameObject* gameObject);

	void ToggleDebug();

	void Terminate();

private:
	Physics2D() {}

	std::vector<GameObject*> m_gameObject;

	static bool m_debugOn;
};

#endif