#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL.h"
#include "Sprite.h"
#include "GameState.h"

class MenuState : public GameState
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

	// Implement Singleton Pattern
	static MenuState* Instance()
	{
		return &m_MenuState;
	}

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;

	Sprite* menuSprite;
};

#endif