#include "Map.h"
#include <iostream>

void Map::Load(TextureResource *textureResource, char* filename)
{
	TMXParser parser(filename);
	//m_sprite = new Sprite(parser.getImageSource().c_str());
	m_sprite = new Sprite();
	int textureIndex;
	textureResource->LoadTMX(filename, &textureIndex);

	m_sprite->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);

	int tileWidth = parser.getTileWidth();
	int tileHeight = parser.getTileHeight();

	m_width = parser.getWidth();
	m_height = parser.getHeight();

	int i = 0;
	for (int x = 0; x < m_width; x++)
	{
		std::vector<Tile> row;
		tiles.push_back(row);

		for (int y = 0; y < m_height; y++)
		{
			Tile tile(x * tileWidth, y * tileHeight, m_sprite, parser.getRect(x, y));
			tiles[x].push_back(tile);
		}
	}
} 

void Map::Update(float deltaTime)
{

}

void Map::Draw()
{
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			tiles[x][y].Draw();
		}
	}
}

void Map::Clean()
{
	GameObject::Clean();
}