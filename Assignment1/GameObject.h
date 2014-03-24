#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Game.h"
#include "Sprite.h"
#include "TextureResource.h"

class GameObject
{
public:
	GameObject() {}
	~GameObject() {}

	virtual void Load(const char* filename);
	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void Clean();

protected:
	Sprite* m_sprite;
};


#endif