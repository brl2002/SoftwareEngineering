#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "GUIComponent.h"
#include <vector>

class GameState
{
public:
	virtual void Init() = 0;
	virtual void Clean() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(const SDL_Event &e) = 0;

	virtual void HandleKeyInput(const Uint8 *keyState) = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void DrawGUI() = 0;
	virtual void PostUpdate() = 0;

	void ChangeState(GameState* state)
	{
		GameInst::Instance()->ChangeState(state);
	}

protected:
	GameState() {}
};

#endif