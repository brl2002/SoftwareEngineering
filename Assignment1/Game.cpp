#include "Game.h"
#include "PlayState.h"
#include "GameState.h"
#include "Windows.h"
#include <iostream>

Game::~Game()
{
	m_textureResource;
}

void Game::Init(const char* title, int width, int height, bool fullscreen)
{
	SCREEN_HEIGHT = height;
	SCREEN_WIDTH = width;
	int flags = 0;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		Error::log(std::cout, "SDL_Init");
		return;
	}
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		Error::log(std::cout, "IMG_Init");
		return;
	}
	TTF_Init();

	// Set fullscreen or not
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	// Create the window
	m_window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		flags | SDL_WINDOW_OPENGL);
	if (m_window == nullptr)
	{
		Error::log(std::cout, "CreateWindow");
		return;
	}

	// Create the renderer
	m_renderer = SDL_CreateRenderer(m_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr)
	{
		Error::log(std::cout, "CreateRenderer");
		return;
	}

	m_textureResource = new TextureResource(m_renderer);

	m_bFullscreen = fullscreen;
	m_bRunning = true;

	LoadGame();
}

void Game::LoadGame()
{
	SDL_Event e;

	ChangeState(PlayState::Instance());

	// game loop implementation
	unsigned int currentTime, prevTime = 0;
		
	while (m_bRunning)
	{
		while(SDL_PollEvent(&e))
		{
			HandleEvents(e);
		}

		HandleKeyInput(SDL_GetKeyboardState(NULL));

		currentTime = SDL_GetTicks();

		float deltaTime = (float)((currentTime - prevTime) / 1000.0f);

		Update(deltaTime);

		Draw();

		prevTime = currentTime;
	}

	Clean();
}

void Game::ChangeState(GameState* state)
{
	// clean up the current state
	if (!states.empty())
	{
		states.back()->Clean();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(GameState* state)
{
	// pause current state
	if (!states.empty())
	{
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PopState()
{
	// clean up the current state
	if (!states.empty())
	{
		states.back()->Clean();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty())
	{
		states.back()->Resume();
	}
}

void Game::HandleEvents(const SDL_Event &e)
{
	// let the state handle events
	states.back()->HandleEvents(e);
}

void Game::HandleKeyInput(const Uint8 *keyState)
{
	states.back()->HandleKeyInput(keyState);
}

void Game::Update(float deltaTime)
{
	// let the state update the game
	states.back()->Update(deltaTime);
}

void Game::Draw()
{
	SDL_RenderClear(m_renderer);

	// let the state draw the screen
	states.back()->Draw();

	SDL_RenderPresent(m_renderer);
}

void Game::Clean()
{
	while (!states.empty())
	{
		states.back()->Clean();
		states.pop_back();
	}

	m_textureResource->ReleaseTextures();

	// shutdown SDL
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}