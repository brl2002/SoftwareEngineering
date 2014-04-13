#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_TTF.h"
#include "SDL_image.h"
#include "Error.h"
#include "Sprite.h"
#include "TextureResource.h"
#include "Singleton.h"
#include <vector>
#include <iostream>

class GameState;
class BattleState;
class TextureResource;
class Factory;
class Physics2D;

class Game
{
public:
	~Game();

	void Init(const char* title, int width, int height, bool fullscreen);
	void Clean();

	void ChangeState(GameState* state);
	void StartBattleStateInstance();
	void PushState(GameState* state);
	void PopState();

	void HandleEvents(const SDL_Event &e);
	void HandleKeyInput(const Uint8 *keyState);
	void Update(float deltaTime);
	void Draw();

	bool Running() { return m_bRunning; };
	void Quit() { m_bRunning = false; };

	SDL_Renderer* GetRenderer() const { return m_renderer; }

	TextureResource* GetTextureResource() const { return m_textureResource; }

	int GetScreenWidth() { return SCREEN_WIDTH; }
	int GetScreenHeight() { return SCREEN_HEIGHT; }

	TTF_Font *GetFont() { return m_font; }

private:
	void LoadGame();
	float GetTime();

	Game() {}
	friend class Singleton<Game>;

	// Stack of states
	std::vector<GameState*> states;

	SDL_Renderer* m_renderer;
	SDL_Window* m_window;

	TextureResource *m_textureResource;

	TTF_Font* m_font;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	bool m_bRunning;
	bool m_bFullscreen;

	BattleState *m_battleStateInst;
};
typedef Singleton<Game> GameInst; // instance of the game

class Utility
{
public:
	static void logSDLError(std::ostream &os, const std::string &msg)
	{
		os << msg << " error: " << SDL_GetError() << std::endl;
	}
};

#endif