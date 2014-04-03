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

	
	Factory::getInstance()->CreateNavPlayer();
	m_pNavPlayer = Factory::getInstance()->GetNavPlayer();

	m_pMap = new Map(m_pNavPlayer);
	m_pMap->Load(GameInst::Instance()->GetTextureResource(), "../res/maps/map.tmx");

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
			case SDLK_d:
				m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX() + 1, m_pNavPlayer->GetTileY());
				break;
			case SDLK_a:
				m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX() - 1, m_pNavPlayer->GetTileY());
				break;
			case SDLK_w:
				m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX(), m_pNavPlayer->GetTileY() - 1);
				break;
			case SDLK_s:
				m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX(), m_pNavPlayer->GetTileY() + 1);
				break;
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
	/*if (keyState[SDL_SCANCODE_D])
		
	else if (keyState[SDL_SCANCODE_A])
		

	if (keyState[SDL_SCANCODE_W])
		
	else if (keyState[SDL_SCANCODE_S])
		m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX(), m_pNavPlayer->GetTileY() + 1);*/
}

void PlayState::Update(float deltaTime)
{
	m_pMap->Update(deltaTime);
	m_pNavPlayer->Update(deltaTime);

	Physics2D::getInstance().Update();
}

void PlayState::Draw()
{
	m_pMap->DrawBackground();

	m_pNavPlayer->Draw();

	m_pMap->DrawForeground();

	Physics2D::getInstance().DebugDraw();
}

void PlayState::PostUpdate()
{

}

void PlayState::Clean()
{
	m_pMap->Clean();
	delete m_pMap;

	Factory::getInstance()->DestoryNavPlayer();

	std::cout << "PlayState Clean Successful" << std::endl;
}