#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player() {}
	~Player() {}

	void Load(TextureResource *textureResource, char* filename);
	void Update(float deltaTime);
	void Draw();
	void Clean();
};

#endif