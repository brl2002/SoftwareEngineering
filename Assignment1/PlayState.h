#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "SDL.h"
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "Map.h"
#include <vector>

class PlayState : public GameState
{
public:
	std::vector<GameObject*> GameObjects;

	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update(float deltaTime);
	void Draw();

	// Implement Singleton Pattern
	static PlayState* Instance()
	{
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;

	Map* map;
};

#endif