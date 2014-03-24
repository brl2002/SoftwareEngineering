#include "Sprite.h"
#include "Game.h"
#include <iostream>

Sprite::Sprite()
{
	// The final optimized image
	m_texture = NULL;

	// Load image at specified path
	//SDL_Surface* loadedSurface = IMG_Load(pfile);

	//if (loadedSurface == NULL)
	//{
	//	Error::log(std::cout, "IMG_Load");
	//	exit(EXIT_FAILURE);
	//}
	//else
	//{
	//	// Convert surface to screen format
	//	m_texture = SDL_CreateTextureFromSurface(GameInst::Instance()->GetRenderer(), loadedSurface);
	//	if (m_texture == nullptr)
	//	{
	//		Error::log(std::cout, "CreateTextureFromSurface");
	//		exit(EXIT_FAILURE);
	//	}

	//	// Get rid of old loaded surface
	//	SDL_FreeSurface(loadedSurface);
	//}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_texture);
}

void Sprite::BindTexture(TextureResource *textureResource, int bindIndex)
{
	m_texture = textureResource->GetTexture(bindIndex);
}

bool Sprite::Draw(int x, int y)
{
	if (m_texture == NULL)
	{
		return false;
	} 
	
	// Get width and height of loaded image
	int w, h;
	SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, NULL, &destR);

	return true;
}

bool Sprite::Draw(int x, int y, int x2, int y2, int width, int height) 
{
	if (m_texture == NULL)
	{
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = x;
	destR.w = width;
	destR.h = height;

	SDL_Rect srcR;

	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, &srcR, &destR);

	return true;
}

bool Sprite::Draw(int x, int y, SDL_Rect rect) 
{
	if (m_texture == NULL)
	{
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;
	destR.w = rect.w;
	destR.h = rect.h;

	SDL_RenderCopy(GameInst::Instance()->GetRenderer(), m_texture, &rect, &destR);

	return true;
}