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

	m_tilesVisibleX = (GameInst::Instance()->GetScreenWidth()) / m_tileWidth;
	m_tilesVisibleY = (GameInst::Instance()->GetScreenHeight() + m_tileHeight) / m_tileHeight;

	m_midX = m_tilesVisibleX / 2;
	m_midY = m_tilesVisibleY / 2;

	m_mapEdges.x = 0;
	m_mapEdges.y = 0;
	m_mapEdges.w = m_width;
	m_mapEdges.h = m_height;

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
					tile = new Tile(x, y, m_sprite, *r);
				}

				tiles[x].push_back(tile);
			}
		}

		m_map.push_back(tiles);
	}

	m_blocked = parser.getBlocked();

	Move(0, 0);
} 

void Map::Move(int x, int y)
{
	m_viewport.x = m_pNavPlayer->GetTileX() - m_midX;
	m_viewport.y = m_pNavPlayer->GetTileY() - m_midY;
	m_viewport.w = m_tilesVisibleX;
	m_viewport.h = m_tilesVisibleY;

	SDL_Rect nextView = {
		m_viewport.x + x,
		m_viewport.y + y,
		m_viewport.w,
		m_viewport.h
	};

	SDL_Rect clamped = ClampViewport(m_viewport, m_mapEdges);
	SDL_Rect nextClamped = ClampViewport(nextView, m_mapEdges);

	if (clamped.x == m_viewport.x && nextView.x == nextClamped.x)
		m_xMoving = true;
	else
		m_xMoving = false;

	if (clamped.y == m_viewport.y  && nextView.y == nextClamped.y)
		m_yMoving = true;
	else
		m_yMoving = false;

	if (m_xMoving || m_yMoving)
		m_viewport = nextClamped;
	else
		m_viewport = clamped;
}

void Map::Update(float deltaTime)
{
	if (m_position != m_destination)
	{
		m_position = Vector3::lerp(m_previous, m_destination, m_time);
		m_time += deltaTime * m_pNavPlayer->GetMoveSpeed();

		if (m_time >= 1)
		{
			m_position = m_destination;
			m_time = 0;
		}
	}
}

void Map::DrawBackground()
{
	for (int l = 0; l < m_numLayers - 1; l++)
	{
		int _x = 0;
		for (int x = m_viewport.x; x < m_viewport.x + m_viewport.w; x++)
		{
			int _y = 0;
			for (int y = m_viewport.y; y < m_viewport.y + m_viewport.h; y++)
			{
				if (m_map[l][x][y] != nullptr)
					m_map[l][x][y]->Draw(_x * m_tileWidth, _y * m_tileHeight);

				_y++;
			}
			_x++;
		}
	}
}

void Map::DrawForeground()
{
	int _x = 0;
	for (int x = m_viewport.x; x < m_viewport.x + m_viewport.w; x++)
	{
		int _y = 0;
		for (int y = m_viewport.y; y < m_viewport.y + m_viewport.h; y++)
		{
			if (m_map[m_numLayers - 1][x][y] != nullptr)
				m_map[m_numLayers - 1][x][y]->Draw(_x * m_tileWidth, _y * m_tileHeight);

			_y++;
		}
		_x++;
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

SDL_Rect Map::ClampViewport(SDL_Rect small, SDL_Rect large)
{
	SDL_Rect newRect;

	newRect.x = small.x;
	newRect.y = small.y;

	if (small.x < large.x)
	{
		newRect.x = large.x;
	}
	else if (small.x + small.w > large.x + large.w)
	{
		newRect.x = large.x + large.w - small.w;
	}

	if (small.y < large.y)
	{
		newRect.y = large.y;
	}
	else if (small.y + small.h > large.y + large.h)
	{
		newRect.y = large.y + large.h - small.h;
	}

	newRect.w = small.w;
	newRect.h = small.h;

	return newRect;
}

bool Map::CanMoveHere(int x, int y)
{
	for (auto i = m_blocked.begin(); i != m_blocked.end(); i++)
	{
		if ((x >= i->x && x < i->x + i->w) && (y >= i->y && y < i->y + i->h))
			return false;
	}

	return true;
}