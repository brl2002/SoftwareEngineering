#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Sprite.h"
#include "TextureResource.h"
#include "Collider.h"
#include "Vector3.h"

class Collider;
class TextureResource;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Load(TextureResource *textureResource, const char* filename);
	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void Clean();

	void BindTexture(TextureResource *textureResource, int bindIndex);

	void Enable();
	void Disable();
	bool IsEnabled();

	void addCollider(Collider* collider);
	Collider *getCollider() const;

	void SetDimension(float width, float height);

	void SetPosition(float x, float y);
	float GetVelocityX();
	float GetVelocityY();
	void SetVelocity(float x, float y);

	Vector3& GetPosition();
	float GetHalfWidth() { return m_halfWidth; }
	float GetHalfHeight() { return m_halfHeight; }
	float GetWidth() { return m_halfWidth*2; }
	float GetHeight() { return m_halfHeight*2; }

	virtual void onCollision(GameObject* other) {};

protected:
	bool m_enabled;

	Vector3 m_position;
	float m_halfWidth, m_halfHeight;

	float m_vx, m_vy;

	Sprite *m_sprite;
	Collider* m_collider;
};


#endif