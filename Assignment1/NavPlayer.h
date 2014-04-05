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
	float GetMoveSpeed() { return m_moveSpeed; }

private:
	XMLTranscoder *transcoder;
	
	Vector3 m_destination;
	Vector3 m_previous;

	float m_time;
	float m_moveSpeed;

	int m_x, m_y;
};

#endif