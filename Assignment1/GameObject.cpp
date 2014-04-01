#include "GameObject.h"

GameObject::GameObject() : m_enabled(true), m_collider(NULL), m_vx(0), m_vy(0)
{

}

GameObject::~GameObject()
{
	delete m_collider;
	m_collider = nullptr;
}

void GameObject::Load(TextureResource *textureResource, const char* filename)
{
	m_sprite = new Sprite();

	int textureIndex;
	textureResource->LoadTexture(filename, &textureIndex);

	m_sprite->BindTexture(textureResource, textureIndex);
}

void GameObject::BindTexture(TextureResource *textureResource, int bindTexture)
{
	m_sprite->BindTexture(textureResource, bindTexture);
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{
	m_sprite->Draw(0, 0);
}

void GameObject::Clean()
{
	delete m_sprite;
}

void GameObject::SetDimension(float width, float height)
{
	m_halfWidth = width/2;
	m_halfHeight = height/2;
}

void GameObject::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

Vector3& GameObject::GetPosition()
{
	return m_position;
}

void GameObject::addCollider(Collider* collider)
{
	m_collider = collider; 
	m_collider->SetGameObject(this);
}

Collider* GameObject::getCollider() const
{
	return m_collider;
}

float GameObject::GetVelocityX() { return m_vx; }
float GameObject::GetVelocityY() { return m_vy; }

void GameObject::SetVelocity(float x, float y)
{
	m_vx = x;
	m_vy = y;
}

void GameObject::Enable() { m_enabled = true; }
void GameObject::Disable() { m_enabled = false; }
bool GameObject::IsEnabled() { return m_enabled; }