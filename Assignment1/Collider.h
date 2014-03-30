#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"

class Component;
class Character;

class Collider : public Component
{
public:
	Collider(double x, double y, double width, double height) : m_x(x), m_y(y), m_width(width), m_height(height), m_colliding(0) {}

	~Collider() {}

	bool IsColliding(GameObject *other);

	void colliderReset();
	bool GetCollisionFlag();

	double getWidth() const { return m_width; }
	double getHeight() const { return m_height; }

private:
	double m_x;
	double m_y;
	double m_width;
	double m_height;

	bool m_colliding;
};

#endif