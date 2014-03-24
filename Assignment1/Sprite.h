#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include "SDL_image.h"
#include "Error.h"
#include "TextureResource.h"

class TextureResource;

class Sprite
{
public:
	Sprite();
	~Sprite();

	void BindTexture(TextureResource *textureResource, int bindIndex);

	bool Draw(int x, int y);
	bool Draw(int x, int y, int x2, int y2, int width, int height);
	bool Draw(int x, int y, SDL_Rect rect);

private:
	SDL_Texture *m_texture;
	SDL_Renderer *m_renderer;
	TextureResource *m_textureResource;
	int m_bindIndex;
};

#endif