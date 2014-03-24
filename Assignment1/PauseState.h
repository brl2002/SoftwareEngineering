#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL.h"
#include "Sprite.h"
#include "GameState.h"

class PauseState : public GameState
{
public:
	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update(float deltaTime);
	void Draw();

	// Implement Singleton Pattern
	static PauseState* Instance()
	{
		return &m_PauseState;
	}

protected:
	PauseState() {}

private:
	static PauseState m_PauseState;

	Sprite* pauseSprite;
};

#endif