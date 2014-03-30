#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "SDL.h"
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "Map.h"
#include "NavPlayer.h"
#include "Factory.h"
#include "Physics2D.h"
#include <vector>

class PlayState : public GameState
{
public:
	std::vector<GameObject*> GameObjects;

	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents(const SDL_Event &e);
	void HandleKeyInput(const Uint8 *keyState);
	void Update(float deltaTime);
	void Draw();
	void PostUpdate();

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

	NavPlayer *m_navPlayer;
};

#endif