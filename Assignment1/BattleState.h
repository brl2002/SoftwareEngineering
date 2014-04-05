#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "GameState.h"

class BattleState : public GameState
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
	static BattleState* Instance()
	{
		return &m_BattleState;
	}

protected:
	BattleState() {}

private:
	static BattleState m_BattleState;
};

#endif