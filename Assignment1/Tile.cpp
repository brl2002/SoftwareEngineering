#include "Tile.h"

Tile::Tile(int x, int y, Sprite* spriteSheet, SDL_Rect rect)
{
	m_x = x;
	m_y = y;
	m_spriteSheet = spriteSheet;
	m_rect = rect;
	//m_xOffset = 0;
	//m_yOffset = 0;
}

void Tile::Update(float deltaTime)
{

}

void Tile::Draw(int x, int y)
{
	if (m_spriteSheet != nullptr)
		m_spriteSheet->Draw(x, y, m_rect);
}

void Tile::Clean()
{

}