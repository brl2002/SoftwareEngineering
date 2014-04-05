#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "NavState.h"
#include "PauseState.h"
#include "TMXParser.h"

NavState NavState::m_PlayState;

void NavState::Init()
{
	Factory::getInstance()->CreateNavPlayer();
	m_pNavPlayer = Factory::getInstance()->GetNavPlayer();

	m_pMap = new Map(m_pNavPlayer);
	m_pMap->Load(GameInst::Instance()->GetTextureResource(), "../res/maps/map.tmx");

	//Physics2D::getInstance().ToggleDebug();
}

void NavState::Pause()
{
	std::cout << "PlayState Paused" << std::endl;
}

void NavState::Resume()
{
	std::cout << "PlayState Resumed" << std::endl;
}

void NavState::HandleEvents(const SDL_Event &e)
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
				m_pNavPlayer->Move(1, 0, m_pMap);
				break;
			case SDLK_a:
				m_pNavPlayer->Move(-1, 0, m_pMap);
				break;
			case SDLK_w:
				m_pNavPlayer->Move(0, -1, m_pMap);
				break;
			case SDLK_s:
				m_pNavPlayer->Move(0, 1, m_pMap);
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

void NavState::HandleKeyInput(const Uint8 *keyState)
{
	/*if (keyState[SDL_SCANCODE_D])
		
	else if (keyState[SDL_SCANCODE_A])
		

	if (keyState[SDL_SCANCODE_W])
		
	else if (keyState[SDL_SCANCODE_S])
		m_pNavPlayer->SetTile(m_pNavPlayer->GetTileX(), m_pNavPlayer->GetTileY() + 1);*/
}

void NavState::Update(float deltaTime)
{
	m_pMap->Update(deltaTime);
	m_pNavPlayer->Update(deltaTime);

	Physics2D::getInstance().Update();
}

void NavState::Draw()
{
	m_pMap->DrawBackground();
	 
	m_pNavPlayer->Draw();

	m_pMap->DrawForeground();

	Physics2D::getInstance().DebugDraw();
}

void NavState::PostUpdate()
{

}

void NavState::Clean()
{
	m_pMap->Clean();
	delete m_pMap;

	Factory::getInstance()->DestoryNavPlayer();

	std::cout << "PlayState Clean Successful" << std::endl;
}