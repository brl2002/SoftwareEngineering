#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
	menuSprite = new Sprite();

	int textureIndex = GameInst::Instance()->GetTextureResource()->LoadTexture("../res/background.bmp");

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

void MenuState::HandleEvents()
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
						GameInst::Instance()->ChangeState(PlayState::Instance());
						break;
				}
		}
	}
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