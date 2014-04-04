#ifndef NAV_STATE_H
#define NAV_STATE_H

#include "SDL.h"
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "Map.h"
#include "NavPlayer.h"
#include "Factory.h"
#include "Physics2D.h"
#include <vector>

class NavState : public GameState
{
public:
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
	static NavState* Instance()
	{
		return &m_PlayState;
	}

protected:
	NavState() {}

private:
	static NavState m_PlayState;

	Map* m_pMap;
	NavPlayer* m_pNavPlayer;
};

#endif