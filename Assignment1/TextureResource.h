#ifndef TEXTURERESOURCE_H
#define TEXTURERESOURCE_H

#include <SDL.h>
#include <vector>

#include "Game.h"
#include "TMXParser.h"

#include <assert.h>

class TextureResource
{
public:
	TextureResource(SDL_Renderer *renderer);
	~TextureResource();

	int LoadTexture(const std::string &file);

	int LoadTMX(const char *file);

	int LoadTextureWithAlphaKey(const char *file, Uint8 r, Uint8 g, Uint8 b);

	SDL_Texture* GetTexture(int boundIndex) const;

	int TotalTextures() { return m_textures.size(); }

private:
	SDL_Renderer *m_renderer;

	std::vector<SDL_Texture*> m_textures;
};

#endif