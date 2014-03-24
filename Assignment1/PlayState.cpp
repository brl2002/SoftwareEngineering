#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "PlayState.h"
#include "PauseState.h"
#include "TMXParser.h"

PlayState PlayState::m_PlayState;

void PlayState::Init()
{
	//player = new Player();
	//player->Load("../res/background.png");	// load image for game object

	//go = new GameObject();
	//go->Load("../res/image.png");

	//GameObjects.push_back(player);
	//GameObjects.push_back(go);

	map = new Map();
	map->Load("../res/map.tmx");

	GameObjects.push_back(map);
}

void PlayState::Pause()
{
	std::cout << "PlayState Paused" << std::endl;
}

void PlayState::Resume()
{
	std::cout << "PlayState Resumed" << std::endl;
}

void PlayState::HandleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				GameInst::Instance()->Quit();
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_SPACE:
						GameInst::Instance()->PushState(PauseState::Instance());
						break;
				}
		}
	}
}

void PlayState::Update(float deltaTime)
{
	for (unsigned int i = 0; i < GameObjects.size(); i++)
	{
		if (!GameObjects[i])
		{
			continue;
		}

		GameObjects[i]->Update(deltaTime);
	}
}

void PlayState::Draw()
{
	for (unsigned int i = 0; i < GameObjects.size(); i++)
	{
		if (!GameObjects[i])
		{
			continue;
		}

		GameObjects[i]->Draw();
	}
}

void PlayState::Clean()
{
	for (unsigned int i = 0; i < GameObjects.size(); i++)
	{
		if (!GameObjects[i])
		{
			continue;
		}

		GameObjects[i]->Clean();
	}
	GameObjects.clear();

	std::cout << "PlayState Clean Successful" << std::endl;
}