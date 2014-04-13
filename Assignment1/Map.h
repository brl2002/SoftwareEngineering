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

	void Move(int x, int y);

	static int GetTileWidth() { return m_tileWidth; }
	static int GetTileHeight() { return m_tileWidth; }

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }

	bool GetXMoving() { return m_xMoving; }
	bool GetYMoving() { return m_yMoving; }
	bool IsLerping() { return (m_viewport.x != m_nextViewport.x || 
		m_viewport.y != m_nextViewport.y) && (m_xMoving || m_yMoving); }

	bool CanMoveHere(int x, int y);

private:
	SDL_Rect ClampViewport(SDL_Rect small, SDL_Rect large);

	int m_width;
	int m_height;
	int m_numLayers;

	int m_tilesVisibleX, m_tilesVisibleY;
	int m_midX, m_midY;

	SDL_Rect m_viewport;
	SDL_Rect m_nextViewport;

	SDL_Rect m_mapEdges;
	std::vector<SDL_Rect> m_blocked;

	bool m_xMoving, m_yMoving;
	int m_xDir, m_yDir;

	Vector3 m_offset;
	float m_time;

	static int m_tileWidth, m_tileHeight;

	int m_boundTextureIndex;

	NavPlayer* m_pNavPlayer;

	typedef std::vector<std::vector<Tile*>> TilesArray;
	std::vector<TilesArray> m_map;
};

#endif