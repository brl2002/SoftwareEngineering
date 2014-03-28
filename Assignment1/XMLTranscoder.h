#include "tinyxml2.h"
#include "Animation.h"
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <vector>

#ifndef XMLTRANSCODER_H
#define XMLTRANSCODER_H

class XMLTranscoder
{
public:
	XMLTranscoder();
	~XMLTranscoder();

	XMLTranscoder(const XMLTranscoder& copy);

	XMLTranscoder& operator=(const XMLTranscoder& other);

	void Transcode(const char* fileName);

	Animation* GetAnimation(int index) const;

	const int TotalAnimations();

	const int TotalFrames(int animIndex);

private:
	std::vector<Animation*> m_AnimSprites;

	int m_Width, m_Height;

private:
	void AddAnimSprite(Animation* animSprite);
};

#endif