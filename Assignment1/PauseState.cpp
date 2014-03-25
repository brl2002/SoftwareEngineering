#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init()
{
	pauseSprite = new Sprite();

	int textureIndex;
	GameInst::Instance()->GetTextureResource()->LoadTexture("../res/image.bmp", &textureIndex);

	pauseSprite->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);
}

void PauseState::Pause() {}

void PauseState::Resume() { }

void PauseState::HandleEvents()
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
						GameInst::Instance()->PopState();
						break;
				}
		}
	}
}

void PauseState::Update(float deltaTime)
{

}

void PauseState::Draw()
{
	pauseSprite->Draw(0, 0);
}

void PauseState::Clean()
{
	
}