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

private:
	int _x, _y;
	Sprite* m_spriteSheet;
	SDL_Rect m_rect;
};

#endif