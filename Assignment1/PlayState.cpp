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
	map->Load(GameInst::Instance()->GetTextureResource(), "../res/map.tmx");

	Factory::getInstance()->CreateNavPlayer();
	m_navPlayer = Factory::getInstance()->GetNavPlayer();

	Physics2D::getInstance().ToggleDebug();

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

void PlayState::HandleEvents(const SDL_Event &e)
{
	switch (e.type)
	{
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch(e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				GameInst::Instance()->Quit();
				break;
			case SDLK_SPACE:
				GameInst::Instance()->PushState(PauseState::Instance());
				break;
			}
	}
}

void PlayState::HandleKeyInput(const Uint8 *keyState)
{
	if (keyState[SDL_SCANCODE_D])
		m_navPlayer->SetVelocity(100, m_navPlayer->GetVelocityY());
	else if (keyState[SDL_SCANCODE_A])
		m_navPlayer->SetVelocity(-100, m_navPlayer->GetVelocityY());

	if (keyState[SDL_SCANCODE_W])
		m_navPlayer->SetVelocity(m_navPlayer->GetVelocityX(), -100);
	else if (keyState[SDL_SCANCODE_S])
		m_navPlayer->SetVelocity(m_navPlayer->GetVelocityX(), 100);
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

	m_navPlayer->Update(deltaTime);
	m_navPlayer->Move(deltaTime);

	Physics2D::getInstance().Update();
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

	m_navPlayer->Draw();

	Physics2D::getInstance().DebugDraw();

	m_navPlayer->SetVelocity(0, 0);
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

	delete map;

	Factory::getInstance()->DestoryNavPlayer();

	std::cout << "PlayState Clean Successful" << std::endl;
}