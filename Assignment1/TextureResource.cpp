#include "TextureResource.h"

TextureResource::TextureResource(SDL_Renderer *renderer) : m_renderer(renderer)
{

}

TextureResource::~TextureResource()
{
	for (int i = 0; i < m_textures.size(); ++i)
	{
		delete m_textures[i];
	}

	m_textures.clear();
}

int TextureResource::LoadTexture(const std::string &file)
{
	SDL_Texture *texture = IMG_LoadTexture(m_renderer, file.c_str());

	if (texture == nullptr)
	{
		Utility::logSDLError(std::cout, "LoadTexture");
		return -1;
	}

	m_textures.push_back(texture);
	return m_textures.size()-1;
}

int TextureResource::LoadTMX(const char *file)
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
	return m_textures.size()-1;
}

int TextureResource::LoadTextureWithAlphaKey(const char *file, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = IMG_Load(file);

	if (surface == nullptr)
	{
		Utility::logSDLError(std::cout, "CreateSurface");
		return -1;
	}

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
	
	texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if(texture == NULL)
    {
        Utility::logSDLError(std::cout, "LoadTexture");
    }

	SDL_FreeSurface(surface);

	m_textures.push_back(texture);
	return m_textures.size()-1;
}

SDL_Texture* TextureResource::GetTexture(int boundTexture) const
{
	assert(boundTexture >= 0 && boundTexture < m_textures.size());

	return m_textures[boundTexture];
}