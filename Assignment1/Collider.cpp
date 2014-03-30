#include "Collider.h"

bool Collider::IsColliding(GameObject* other)
{
	double x = m_gameObject->GetPosition().x - m_gameObject->getCollider()->getWidth() / 2;
	double y = m_gameObject->GetPosition().y - m_gameObject->getCollider()->getHeight() / 2;
	double width = m_gameObject->getCollider()->getWidth();
	double height = m_gameObject->getCollider()->getHeight();

	double other_x = other->GetPosition().x - other->getCollider()->getWidth() / 2;
	double other_y = other->GetPosition().y - other->getCollider()->getHeight() / 2;
	double other_width = other->getCollider()->getWidth();
	double other_height = other->getCollider()->getHeight();

	if (!((x + width) >= other_x))
	{
		return false;
	}
	if (!(x <= (other_x + other_width)))
	{
		return false;
	}
	if (!((y - height) <= other_y))
	{
		return false;
	}
	if (!(y >= (other_y - other_height)))
	{
		return false;
	}

	m_colliding = true;
	return true;
}

bool Collider::GetCollisionFlag()
{
	return m_colliding;
}

void Collider::colliderReset()
{
	m_colliding = false;
}