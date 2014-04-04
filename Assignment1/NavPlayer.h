#ifndef NAVPLAYER_H
#define NAVPLAYER_H

#include "GameObject.h"
#include "XMLTranscoder.h"
#include "Map.h"

class Map;

class NavPlayer : public GameObject
{
public:
	NavPlayer();

	~NavPlayer();

	void Update(float deltaTime);

	void Draw();

	void Move(int x, int y, Map* map);

	float GetTileX() { return m_x; }
	float GetTileY() { return m_y; }

private:
	XMLTranscoder *transcoder;
	
	int m_x, m_y;
};

#endif