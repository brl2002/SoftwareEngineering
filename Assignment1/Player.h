#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player() {}
	~Player() {}

	void Load(char* filename);
	void Update(float deltaTime);
	void Draw();
	void Clean();
};

#endif