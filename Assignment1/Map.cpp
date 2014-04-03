#include "Map.h"
#include <iostream>

int Map::m_tileHeight = 0;
int Map::m_tileWidth = 0;

Map::Map(NavPlayer *player)
{
	m_pNavPlayer = player;
}

void Map::Load(TextureResource *textureResource, char* filename)
{
	TMXParser parser(filename);

	//m_sprite = new Sprite(parser.getImageSource().c_str());
	m_sprite = new Sprite();
	int textureIndex;
	textureResource->LoadTMX(filename, &textureIndex);

	m_sprite->BindTexture(GameInst::Instance()->GetTextureResource(), textureIndex);

	Map::m_tileWidth = parser.getTileWidth();
	Map::m_tileHeight = parser.getTileHeight();

	m_width = parser.getWidth();
	m_height = parser.getHeight();

	m_numLayers = parser.getNumLayers();

	int i = 0;

	for (int l = 0; l < m_numLayers; l++)
	{
		TilesArray tiles;
		for (int x = 0; x < m_width; x++)
		{
			std::vector<Tile*> row;
			tiles.push_back(row);

			for (int y = 0; y < m_height; y++)
			{
				SDL_Rect* r = parser.getRect(x, y, l);
				Tile* tile = nullptr;

				if (r != nullptr)
				{
					tile = new Tile(x * m_tileWidth, y * m_tileHeight, m_sprite, *r);
				}

				tiles[x].push_back(tile);
			}
		}

		m_map.push_back(tiles);
	}
} 

void Map::Update(float deltaTime)
{
	std::cout << m_pNavPlayer->GetPosition().x << std::endl;
	for (int l = 0; l < m_numLayers; l++)
	{
		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				//if (m_map[l][x][y] != nullptr)
					//m_map[l][x][y]->setOffset(-m_pNavPlayer->GetPosition().x, 
						//					  -m_pNavPlayer->GetPosition().y);
			}
		}
	}
}

void Map::DrawBackground()
{
	for (int l = 0; l < m_numLayers - 1; l++)
	{
		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				if (m_map[l][x][y] != nullptr)
					m_map[l][x][y]->Draw();
			}
		}
	}
}

void Map::DrawForeground()
{
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			if (m_map[m_numLayers - 1][x][y] != nullptr)
				m_map[m_numLayers - 1][x][y]->Draw();
		}
	}
}

void Map::Clean()
{
	GameObject::Clean();

	for (int l = 0; l < m_numLayers; l++)
	{
		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				if (m_map[l][x][y] != nullptr)
				{
					delete m_map[l][x][y];
					m_map[l][x][y] = nullptr;
				}
			}
		}
	}
}