#ifndef NAVPLAYER_H
#define NAVPLAYER_H

#include "GameObject.h"
#include "XMLTranscoder.h"
#include "Map.h"

class GameObject;
class XMLTranscoder;

class NavPlayer : public GameObject
{
public:
	NavPlayer();

	~NavPlayer();

	void Update(float deltaTime);

	void Draw();

	void SetTile(int x, int y);

	float GetTileX() { return m_x; }
	float GetTileY() { return m_y; }

private:
	XMLTranscoder *transcoder;
	
	int m_x, m_y;
};

#endif