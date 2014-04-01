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

	m_pMap = new Map();
	m_pMap->Load(GameInst::Instance()->GetTextureResource(), "../res/maps/map.tmx");

	Factory::getInstance()->CreateNavPlayer();
	m_pNavPlayer = Factory::getInstance()->GetNavPlayer();

	Factory::getInstance()->CreateBox();

	Physics2D::getInstance().ToggleDebug();
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
		m_pNavPlayer->SetVelocity(100, m_pNavPlayer->GetVelocityY());
	else if (keyState[SDL_SCANCODE_A])
		m_pNavPlayer->SetVelocity(-100, m_pNavPlayer->GetVelocityY());

	if (keyState[SDL_SCANCODE_W])
		m_pNavPlayer->SetVelocity(m_pNavPlayer->GetVelocityX(), -100);
	else if (keyState[SDL_SCANCODE_S])
		m_pNavPlayer->SetVelocity(m_pNavPlayer->GetVelocityX(), 100);
}

void PlayState::Update(float deltaTime)
{
	m_pMap->Update(deltaTime);
	m_pNavPlayer->Update(deltaTime);
	//m_pNavPlayer->Move(deltaTime);

	Physics2D::getInstance().Update(deltaTime);
}

void PlayState::Draw()
{
	m_pMap->DrawBackground();

	m_pNavPlayer->Draw();

	m_pMap->DrawForeground();

	Physics2D::getInstance().DebugDraw();

	m_pNavPlayer->SetVelocity(0, 0);
}

void PlayState::PostUpdate()
{

}

void PlayState::Clean()
{
	m_pMap->Clean();
	delete m_pMap;

	Factory::getInstance()->DestoryNavPlayer();

	Factory::getInstance()->DestroyBox();

	std::cout << "PlayState Clean Successful" << std::endl;
}