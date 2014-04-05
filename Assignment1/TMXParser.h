#ifndef TMX_PARSER
#define TMX_PARSER

#include "tinyxml2.h"
#include "Sprite.h"
#include <string>
#include <vector>

class TMXParser 
{
public:
	TMXParser(const char* filename);
	~TMXParser() {};

	int getTileHeight() { return m_tileHeight; };
	int getTileWidth() { return m_tileWidth; };
	int getWidth() { return m_width; };
	int getHeight() { return m_height; };

	std::string getImageSource() { return m_imageSource; };
	std::vector<SDL_Rect> getRects() { return m_rects; };
	//std::vector<int> getGIDs() { return m_gid; };

	int getNumLayers() { return m_numLayers; }

	SDL_Rect* getRect(int x, int y, int layer);
	std::vector<SDL_Rect> getBlocked() { return m_blocked; }

private:
	void ParseXML(const char* filename);
	void LoadRects();

	// Tile sizes
	int m_tileWidth;
	int m_tileHeight;

	// Amount of tiles
	int m_width;
	int m_height;

	std::string m_imageSource;

	// Array of gids
	std::vector<SDL_Rect> m_rects;
	std::vector<std::vector<int>> m_layers;

	// Blocked areas
	std::vector<SDL_Rect> m_blocked;

	// Width and height of source image
	int m_imageWidth;
	int m_imageHeight;

	int m_numLayers;
};

#endif