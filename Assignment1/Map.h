#ifndef MAP_H
#define MAP_H

#include "GameObject.h"
#include "TMXParser.h"
#include "Tile.h"
#include "NavPlayer.h"

class NavPlayer;

class Map : public GameObject
{
public:
	Map(NavPlayer *player);
	~Map() {}

	void Load(TextureResource *textureResource, char* filename);
	void Update(float deltaTime);
	void DrawBackground();
	void DrawForeground();
	void Clean();

	static int GetTileWidth() { return m_tileWidth; }
	static int GetTileHeight() { return m_tileWidth; }

private:
	int m_width;
	int m_height;
	int m_numLayers;

	static int m_tileWidth, m_tileHeight;

	int m_boundTextureIndex;

	NavPlayer* m_pNavPlayer;

	typedef std::vector<std::vector<Tile*>> TilesArray;
	std::vector<TilesArray> m_map;
};

#endif