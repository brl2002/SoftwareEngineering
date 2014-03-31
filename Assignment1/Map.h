#ifndef MAP_H
#define MAP_H

#include "GameObject.h"
#include "TMXParser.h"
#include "Tile.h"

class Map : public GameObject
{
public:
	Map() {}
	~Map() {}

	void Load(TextureResource *textureResource, char* filename);
	void Update(float deltaTime);
	void DrawBackground();
	void DrawForeground();
	void Clean();

private:
	int m_width;
	int m_height;
	int m_numLayers;

	int m_boundTextureIndex;

	typedef std::vector<std::vector<Tile*>> TilesArray;
	std::vector<TilesArray> m_map;
};

#endif