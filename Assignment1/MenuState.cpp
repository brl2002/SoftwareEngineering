#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
	menuSprite = new Sprite();

	int textureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTexture("../res/background.bmp", &textureIndex);

	menuSprite->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);
}

void MenuState::Pause()
{
	std::cout << "MenuState Paused" << std::endl;
}

void MenuState::Resume()
{
	std::cout << "MenuState Resumed" << std::endl;
}

void MenuState::HandleEvents(const SDL_Event &e)
{
	switch (e.type)
	{
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;

		case SDL_KEYDOWN:
			switch(e.key.keysym.sym)
			{
				case SDLK_SPACE:
					GameInst::Instance()->ChangeState(PlayState::Instance());
					break;
			}
	}
}

void MenuState::HandleKeyInput(const Uint8 *keyState)
{

}

void MenuState::Update(float deltaTime)
{

}

void MenuState::Draw()
{
	menuSprite->Draw(0, 0);
}

void MenuState::Clean()
{
	
}