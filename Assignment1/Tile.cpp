#include "Tile.h"

Tile::Tile(int x, int y, Sprite* spriteSheet, SDL_Rect rect)
{
	_x = x;
	_y = y;
	m_spriteSheet = spriteSheet;
	m_rect = rect;
}

void Tile::Update(float deltaTime)
{

}

void Tile::Draw()
{
	m_spriteSheet->Draw(_x, _y, m_rect);
}

void Tile::Clean()
{

}