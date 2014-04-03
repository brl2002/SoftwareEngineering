#ifndef TILE_H
#define TILE_H

#include "Sprite.h";

class Tile
{
public:
	Tile(int x, int y, Sprite* m_spriteSheet, SDL_Rect rect);

	void Update(float deltaTime);
	void Draw();
	void Clean();

	void setOffset(int xOff, int yOff) { m_xOffset = xOff;  m_yOffset = yOff; }

private:
	int m_x, m_y;
	Sprite* m_spriteSheet;
	SDL_Rect m_rect;

	int m_xOffset, m_yOffset;
};

#endif