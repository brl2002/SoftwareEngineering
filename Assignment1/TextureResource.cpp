#include "TextureResource.h"

TextureResource::TextureResource(SDL_Renderer *renderer) : m_renderer(renderer)
{

}

void TextureResource::LoadTexture(const std::string &file, int *queryIndex)
{
	SDL_Texture *texture = IMG_LoadTexture(m_renderer, file.c_str());

	if (texture == nullptr)
	{
		Utility::logSDLError(std::cout, "LoadTexture");
		*queryIndex = -1;
		return;
	}

	m_textures.push_back(texture);
	*queryIndex = m_textures.size()-1;
}

void TextureResource::LoadTMX(const char *file, int *queryIndex)
{
	TMXParser parser(file);

	SDL_Surface* loadedSurface = IMG_Load(parser.getImageSource().c_str());
	SDL_Texture* texture;

	if (loadedSurface == NULL)
	{
		Error::log(std::cout, "IMG_Load");
		exit(EXIT_FAILURE);
	}
	else
	{
		// Convert surface to screen format
		texture = SDL_CreateTextureFromSurface(GameInst::Instance()->GetRenderer(), loadedSurface);
		if (texture == nullptr)
		{
			Error::log(std::cout, "CreateTextureFromSurface");
			exit(EXIT_FAILURE);
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	m_textures.push_back(texture);
	*queryIndex = m_textures.size()-1;
}

void TextureResource::LoadTextureWithAlphaKey(const char *file, int *queryIndex, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = IMG_Load(file);

	if (surface == nullptr)
	{
		Utility::logSDLError(std::cout, "CreateSurface");
		*queryIndex = -1;
		return;
	}

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
	
	texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if(texture == NULL)
    {
        Utility::logSDLError(std::cout, "LoadTexture");
    }

	SDL_FreeSurface(surface);

	m_textures.push_back(texture);
	*queryIndex = m_textures.size()-1;
}

SDL_Texture* TextureResource::GetTexture(int boundTexture) const
{
	assert(boundTexture >= 0 && boundTexture < m_textures.size());

	return m_textures[boundTexture];
}

void TextureResource::ReleaseTextures()
{
	for (int i = 0; i < m_textures.size(); ++i)
	{
		SDL_DestroyTexture(m_textures[i]);
	}

	m_textures.clear();
}