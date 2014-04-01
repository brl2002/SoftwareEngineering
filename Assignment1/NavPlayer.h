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

private:
	XMLTranscoder *transcoder;
};

#endif