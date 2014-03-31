#ifndef FACTORY_H
#define FACTORY_H

#include "Game.h"
#include "Physics2D.h"
#include "GameObject.h"
#include "NavPlayer.h"

#include <vector>

class GameObject;

class Factory
{
public:
	~Factory();

	static Factory *getInstance()
	{
		static Factory instance;
		return &instance;
	}

	void Init();

	void CreateNavPlayer();
	void DestoryNavPlayer();
	NavPlayer *GetNavPlayer();

	void CleanUp();
	void Terminate();

private:
	Factory();

private:
	std::vector<GameObject*> m_deleteBuffer;

	NavPlayer *m_pNavPlayer;
};

#endif