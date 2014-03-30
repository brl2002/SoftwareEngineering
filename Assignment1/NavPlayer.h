#ifndef NAVPLAYER_H
#define NAVPLAYER_H

#include "GameObject.h"
#include "XMLTranscoder.h"

class GameObject;
class XMLTranscoder;

class NavPlayer : public GameObject
{
public:
	NavPlayer();

	~NavPlayer();

	void Update(float deltaTime);

	void Draw();

	void SetPostion(float x, float y);

	float GetVelocityX() { return m_vx; }

	float GetVelocityY() { return m_vy; }

	void SetVelocity(float x, float y);

	void Move(float dt);

private:
	XMLTranscoder *transcoder;
	float m_vx, m_vy;
};

#endif